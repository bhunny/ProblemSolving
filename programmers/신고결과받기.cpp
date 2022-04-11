#include <string>
#include <vector>
//for test
#include <iostream>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    vector<int> answer(id_list.size(), 0);
    vector<int> result(id_list.size(), 0);
    vector<vector<int>> chk(id_list.size(), vector<int>(report.size(), 0));

    while (report.size())
    {
        string s = report.back();
        stringstream sstream(s);
        string word;
        vector<string> words;
        while (getline(sstream, word, ' '))
        {
            words.push_back(word);
        }
        report.pop_back();
        for (int i = 0; i < id_list.size(); i++)
        {
            if (words[0] == id_list[i])
            {
                for (int j = 0; j < id_list.size(); j++)
                {
                    if (words[1] == id_list[j])
                    {
                        // cout << words[0] << ' '<<words[1];
                        if (chk[i][j] == 1)
                            continue;
                        result[j]++;
                        chk[i][j] = 1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < id_list.size(); i++)
    {
        //cout<<result[i]<<'\n';
        for (int j = 0; j < id_list.size(); j++)
        {
            if (chk[i][j] == 1 && result[j] >= k)
            {
                //cout<<i << ' '<< j;
                answer[i]++;
            }
            //cout << chk[i][j];
        }
        //cout<<'\n';
    }
    //     vector<int>result(id_list.size(),0);
    //     for(int i=0;i<id_list.size();i++){
    //         for(int j=0;j<id_list.size();j++){
    //             if(chk[i][j]){
    //                 result[j]++;
    //             }
    //         }

    //     }
    return answer;
}