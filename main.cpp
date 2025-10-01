#include <iostream>
#include <vector>
#include <string>

using namespace std;

int find_min_path(vector<vector<int>> triangle){
    int n = (int)triangle.size();
    for (int i=n-2; i>=0; i--){
        for (int j=0; j<=i; j++){
            triangle[i][j] = triangle[i][j] + min(triangle[i+1][j], triangle[i+1][j+1]);
        }
    }
    return triangle[0][0];
}

int main() {
    vector<vector<int>> triangle;
    char c;
    cin>>c;
    while (c!='[')
        cin>>c;
    int i=0;
    triangle.push_back(vector<int>());
    while (cin>>c){
        if (c==']') break;
        while (c!=']'){
            string str;
            if (c=='[') {
                cin>>c;
                continue;
            }
            while (c!=']' && c!=','){
                str.push_back(c);
                cin>>c;
            }
            if (!str.empty())
                triangle[i].push_back(stoi(str));
            if (c==']') break;
            cin>>c;
        }
        i++;
        triangle.push_back(vector<int>());
    }
    if (!triangle.empty() && triangle.back().empty())
        triangle.pop_back();
    cout<<find_min_path(triangle);
    return 0;
}
