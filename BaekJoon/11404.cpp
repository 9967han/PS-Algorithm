#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#include <stack>
#include <unordered_set>
#include <map>

using namespace std;

vector<string> solution(vector<string> directory, vector<string> command);

int main() {
   cout.tie(NULL);
   cin.tie(NULL);
   ios::ios_base::sync_with_stdio(false);

   vector<string> directory1 = { "/","/hello","/hello/tmp","/root","/root/abcd","/root/abcd/etc","/root/abcd/hello" };
   vector<string> command1 = { "mkdir /root/tmp","cp /hello /root/tmp","rm /hello" };
   vector<string> directory2 = { "/" };
   vector<string> command2 = { "mkdir /a","mkdir /a/b","mkdir /a/b/c","cp /a/b /","rm /a/b/c" };
   vector<string> command = { "mkdir /a","mkdir /a/b","mkdir /a/b/c", "mkdir /a/b/d", "mkdir /habit2", "mkdir /habit", "rm /habit2"};
   solution(directory2, command);

   return 0;
}

bool comp(pair<int, string> a, pair<int, string> b) {
   if (a.first == b.first)return a.second < b.second;
   return a.first > b.first;
}

vector<string> solution(vector<string> directory, vector<string> command) {
   vector<string> result;

   for (int i = 0; i < command.size(); i++) {
      string c = command[i];
      //cout << c << endl;

      if (c.length() > 5 && c.substr(0, 5) == "mkdir") {
         directory.push_back(c.substr(6));
         //cout << "mkdir: " << c.substr(6) << endl;
      }
      else if (c.substr(0, 2) == "cp") {
         //cout << "cp: ";
         string source = "";
         string tmp = "";//마지막 폴더
         int j;
         for (j = 3; j < c.length(); j++) {
            if (c[j] == ' ')break;
            if (c[j] == '/') {
               tmp = "/";
               source += c[j];
               continue;
            }
            source += c[j];
            tmp += c[j];
         }

         string dest = c.substr(j + 1);
         //cout << "tmp:" << tmp << endl;

         //cout << source << "->" << dest << endl;

         int last = directory.size();
         for (j = 0; j < last; j++) {
            string tmpc = directory[j];
            if (tmpc.length() >= source.length() && tmpc.substr(0, source.length()) == source) {
               if (tmpc.length() > source.length() && tmpc[source.length()] != '/')continue;
               string s = "";
               int startidx = 0;
               //cout << "tmpc: " << tmpc << endl;
               for (int k = 0; k < tmpc.length(); k++) {
                  if (tmpc[k] == '/') {
                     s = "/";
                     startidx = k;
                  }
                  else {
                     s += tmpc[k];
                     //cout << s << endl;
                  }
                  if (s == tmp) {
                     //cout << "s: " << s << "== tmp:" << tmp << endl;
                     break;
                  }
               }

               //if (dest == "/")cout << tmpc << " --> " << tmpc.substr(startidx) << endl;
               //else cout << tmpc << " --> " << dest + tmpc.substr(startidx) << endl;
               if (dest == "/")directory.push_back(tmpc.substr(startidx));
               else directory.push_back(dest + tmpc.substr(startidx));
            }
         }
      }
      else if (c.substr(0, 2) == "rm") {
         string prefix = "";
         int j;
         for (j = 3; j < c.length(); j++) {
            if (c[j] == ' ')break;
            prefix += c[j];
         }

         //cout << "rm: " << prefix << " ";

         for (j = 0; j < directory.size(); j++) {
            string tmpc = directory[j];
            if (tmpc.length() >= prefix.length() && tmpc.substr(0, prefix.length()) == prefix) {
               if (tmpc.length() > prefix.length() && tmpc[prefix.length()] != '/' )continue;
               //cout << "remove: " << directory[j] << endl;
               directory[j] = directory[directory.size() - 1];
               directory.pop_back();
               j--;
            }
         }
      }
   }

   sort(directory.begin(), directory.end());
   for (int i = 0; i < directory.size(); i++)cout << directory[i] << endl;

   result = directory;
   return result;
}