#pragma once

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <stack>


using namespace std;


struct State {
     string path;
     vector<bool> used;
};


class Solution{
public:
     vector<string> get_permutations_interative(const string& input) {
          vector<string> res;
          stack<State> intermediate;
          unordered_map<string, bool> seen;
          int n = input.length();
          intermediate.push({"", vector<bool>(n, false)});

          while (!intermediate.empty()) {
               auto cur = intermediate.top();
               intermediate.pop();

               if (cur.path.length() == n) {
                    cout << "Found new result string " << cur.path << endl;
                    res.push_back(cur.path);
                    continue;
               }

               for (int i = 0; i < n; i++) {
                    if (cur.used[i] == true) {
                         continue;
                    }
                    State next = cur;
                    next.path = cur.path + input[i];
                    if (seen.find(next.path) != seen.end()) {
                         continue;
                    } 
                    next.used[i] = true;
                    cout << "Push new intermediate {path = " + next.path << ", used index = " << i << "}" << "to the stack" << endl;
                    seen[next.path] = true;
                    intermediate.push(next);
               }

          }
          return res;
     }

     vector<string> get_permutations_recursive(const string& input) {
          vector<string> res;
          unordered_map<string, bool> seen;
          int n = input.length();
          vector<bool> used(n, false);
          string path;

          backtrack(res, seen, input, used, path);
          return res;
     }

private:
     void backtrack(
          vector<string>& res,
          unordered_map<string, bool>& seen,
          const string& input,
          vector<bool>& used,
          string& path
     ) {
          if (path.length() == input.length()) {
               if (seen.find(path) == seen.end()) {
                    seen[path] = true;
                    res.push_back(path);
               }
               return;
          }

          for (int i = 0; i < input.length(); i++) {
               if (used[i] == true) {
                    continue;
               }

               used[i] = true;
               path.push_back(input[i]);
               backtrack(res, seen, input, used, path);
               path.pop_back();
               used[i] = false;
          }

     }
};
