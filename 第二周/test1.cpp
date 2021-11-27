class Solution {
public:
    //子域名访问计数
    //逐个解析字符串，哈希表记录域名访问次数
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> hash;    //键为域名，值为次数
        for (string &s : cpdomains) {
            string num, domains;
            int i = 0;
            while (s[i] != ' ') i++;    //解析数字
            num = s.substr(0, i);
            int numInt = atoi(s.c_str());
            domains = s.substr(i + 1);      //解析域名
            hash[domains] += numInt;
            for (int j = 0; j < domains.size(); j++) {
                if (domains[j] == '.') {
                    hash[domains.substr(j + 1)] += numInt;  //增加域名访问次数
                }
            }
        }
        vector<string> ans;
        for (auto &pair : hash) {
            ans.push_back(to_string(pair.second) + " " + pair.first);
        }
        return ans;
    }
};