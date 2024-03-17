bool isChar(char c) {
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return true;
  return false;
}

bool isInt(char c) {
  if (c >= '0' && c <= '9') return true;
  return false;
}

class Solution {
 public:
  bool isPalindrome(string s) {
    vector<char> v;
    for (int i = 0; i < s.length(); i++) {
      if (isChar(s[i]) || isInt(s[i])) v.push_back(tolower(s[i]));
    }
    for (int i = 0; i < v.size() / 2; i++) {
      if (v[i] != v[v.size() - 1 - i]) return false;
    }
    return true;
  }
};