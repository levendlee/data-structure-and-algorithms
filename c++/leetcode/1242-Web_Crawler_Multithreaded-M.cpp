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
