// 1242 Web Crawler Multithreaded
// https://leetcode.com/problems/web-crawler-multithreaded

// version: 1; create time: 2020-02-15 16:31:24;
/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */
class Solution {
private:
    mutex tbl_mtx_;

    mutex q_mtx_;
    condition_variable q_cv_;

    unordered_set<string> tbl_;
    queue<string> q_;

    string getHost(const string& url) {
        auto idx0 = url.find("//");
        auto idx1 = url.find('/', idx0 + 2);
        return url.substr(0, idx1 == string::npos ? url.size() : idx1);
    }

    bool hasSameHost(const string& url1, const string& url2) {
        bool res = getHost(url1) == getHost(url2);
        return res;
    }

public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        auto crawler = [&]() {
            while (true) {
                unique_lock<mutex> qlk(q_mtx_);
                if (q_.empty()) break;
                auto url = q_.front(); q_.pop();
                qlk.unlock();

                unique_lock<mutex> tlk(tbl_mtx_);
                if (tbl_.count(url)) {
                    tlk.unlock();
                    continue;
                } else {
                    tbl_.insert(url);
                    tlk.unlock();
                }

                auto next_urls = htmlParser.getUrls(url);

                qlk.lock();
                for (auto& cur_url : next_urls) {
                    if (hasSameHost(url, cur_url)) {
                        q_.push(cur_url);
                    }
                }
                qlk.unlock();
            }
        };

        q_.push(startUrl);
        thread t1(crawler);
        thread t2(crawler);
        thread t3(crawler);
        t1.join();
        t2.join();
        t3.join();

        return vector<string>(tbl_.begin(), tbl_.end());
    }
};

//

class Solution {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        // constexpr char prefix[] = "http://";
        constexpr int prefix_size = 7;

        int sep = startUrl.find('/', prefix_size);
        if (sep == string::npos) sep = startUrl.size();
        string hostName = startUrl.substr(0, sep);

        unordered_set<string> url_set;
        url_set.insert(startUrl);
        
        queue<string> bfs;
        bfs.push(startUrl);

        mutex mtx;
        function<void(string)> query;
        query = [&](string url) {
            auto new_urls = htmlParser.getUrls(url);
            lock_guard<mutex> lock(mtx);
            for (const auto& u : new_urls) {
                if (u.substr(0, hostName.size()) != hostName) continue;
                if (url_set.count(u)) continue;
                url_set.insert(u);
                bfs.push(u);
            }
        };

        while (!bfs.empty()) {
            int search_space = bfs.size();
            vector<thread> threads(search_space);
            for (int i = 0; i < search_space; ++i) {
                string url = bfs.front();
                bfs.pop();
                threads[i] = thread(query, url);
            }
            for (int i = 0; i < search_space; ++i) {
                threads[i].join();
            }
        }

        return vector<string>(url_set.begin(), url_set.end());
    }
};

//
// std::async runs slower than naive std::thread. Condition variable is still
// the best
class Solution {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        // constexpr char prefix[] = "http://";
        constexpr int prefix_size = 7;

        int sep = startUrl.find('/', prefix_size);
        if (sep == string::npos) sep = startUrl.size();
        string hostName = startUrl.substr(0, sep);

        unordered_set<string> url_set;
        url_set.insert(startUrl);

        mutex mtx;
        function<vector<string>(string)> query;
        query = [&](string url) {
            auto new_urls = htmlParser.getUrls(url);
            vector<string> res;
            lock_guard<mutex> lock(mtx);
            for (const auto& u : new_urls) {
                if (u.substr(0, hostName.size()) != hostName || url_set.count(u)) continue;
                url_set.insert(u);
                res.push_back(u);
            }
            return res;
        };

        queue<future<vector<string>>> bfs;
        bfs.push(async(launch::async, query, startUrl));
        while (!bfs.empty()) {
            auto new_urls = bfs.front().get();
            bfs.pop();
            for (const auto& url : new_urls) {
                bfs.push(async(launch::async, query, url));
            }
        }

        return vector<string>(url_set.begin(), url_set.end());
    }
};