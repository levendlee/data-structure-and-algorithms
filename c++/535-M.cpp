class Solution {
private:
    std::unordered_map<string, string> encode_map;
    std::unordered_map<string, string> decode_map;

public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (encode_map.count(longUrl)) {
            return encode_map[longUrl];
        }
        string encoded;
        while (true) {
            const int choice = rand() % 62;
            if (choice <= 9) {
                encoded += choice + '0';
            } else if (choice <= 35) {
                encoded += choice - 9 + 'a';
            } else {
                encoded += choice - 35 + 'A';
            }
            if (!decode_map.count(encoded)) {
                break;
            }
        }
        encode_map[longUrl] = encoded;
        decode_map[encoded] = longUrl;
        return encoded;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return decode_map[shortUrl];
    }
};