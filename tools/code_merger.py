import collections
import os
import re
import typing
from datetime import datetime

from bs4 import BeautifulSoup


def recursive_search_question_list(page_elem: BeautifulSoup) -> BeautifulSoup:
    question_list = page_elem.find('div',
                                   attrs={'class': 'table-responsive question-list-table'})
    if question_list:
        return question_list.find('table').find('tbody')
    for page_elem in page_elem.find_all():
        question_list = recursive_search_question_list(page_elem)
        return question_list


def populate_question_table(question_list: BeautifulSoup) \
        -> typing.Sequence[typing.Tuple[str, str]]:
    tbl = []
    for question in question_list.find_all('tr'):
        q = question.find_all('td')[2]
        name = q.get('value').replace(' ', '_')
        line = q.find('div').find('a').get('href')
        tbl.append((name, line))
    return tbl


def generate_question_table(question_set_html: str) -> typing.Sequence[typing.Tuple[str, str]]:
    with open(question_set_html) as html:
        raw_content = html.read()
    content = BeautifulSoup(raw_content, 'html.parser')
    question_list = recursive_search_question_list(content)
    question_table = populate_question_table(question_list)
    return question_table


CodeFile = collections.namedtuple('CodeFile', ['id', 'level', 'version', 'language',
                                               'content', 'create_time'])


def load_code_files(src_dir: str) -> typing.Mapping[str, typing.Sequence[CodeFile]]:
    files = collections.defaultdict(list)
    for (dirpath, dirnames, filenames) in os.walk(src_dir):
        for filename in filenames:
            filepath = os.path.join(dirpath, filename)
            if re.match("[0-9]{1,4}-[EMH].*\.*", filename):
                segments = filename.split('-')
                if len(segments) == 2:
                    qid = int(segments[0])
                    level, pl = segments[1].split('.')
                    version = 1
                else:
                    qid, level = segments[0:2]
                    qid = int(qid)
                    version, pl = segments[2].split('.')
                with open(filepath) as f:
                    content = f.read()
                timestamp = os.stat(filepath).st_birthtime
                create_time = str(datetime.fromtimestamp(int(timestamp)))
                files[(qid, pl)].append(
                    CodeFile(id=qid, level=level, version=version, language=pl,
                             content=content, create_time=create_time)
                )
            else:
                print("{} is not recognized!".format(filepath))
    return files


def rename_code_files(src_dir: str, dst_dir: str) -> None:
    files = load_code_files(src_dir)
    table = generate_question_table('problems_leetcode.html')
    for _, file_list in files.items():
        base_file = file_list[0]
        filename = "{id}-{name}-{level}.{pl}".format(id=str(base_file.id).zfill(4),
                                                     name=table[base_file.id - 1][0],
                                                     level=base_file.level,
                                                     pl=base_file.language)
        content = []
        if base_file.language == 'cpp':
            comment_sign = '//'
        elif base_file.language == 'py':
            comment_sign = '#'
        else:
            raise TypeError("Unknown programming language")

        content.append("{comment} {id} {name}".format(
            comment=comment_sign,
            id=base_file.id,
            name=table[base_file.id - 1][0].replace('_', ' ')
        ))
        content.append("{comment} {link}".format(
            comment=comment_sign,
            link=table[base_file.id - 1][1]
        ))
        for file in file_list:
            content.append("")
            content.append("{comment} version: {version}; create time: {create_time};".format(
                comment=comment_sign,
                version=file.version,
                create_time=file.create_time
            ))
            content.append(file.content)
            content.append("")

        with open(os.path.join(dst_dir, filename), 'w') as file:
            file.write('\n'.join(content))


rename_code_files("../c++", "c++_tmp")
rename_code_files("../python", "python_tmp")
