// 2607.cpp

#include <iostream>
#include <map>
#include <cmath>

using namespace std;

map<char, int> getMap(string str) {
    // 문자열을 구성하는 알파벳과 알파벳의 출현횟수의 쌍으로 이루어진 맵을 생성한다. 
    map<char, int> mp;
    for (int i = 0; i < str.size(); i++) {
        mp[str[i]]++;
    }
    return mp;
}

int compareMap(map<char, int> mp1, map<char, int> mp2) {
    // 매개변수로 받은 두 맵을 비교한다. 
    //이 때, 항상 mp1에 길이가 더 긴 문자열의 맵이 들어온다. 
    int same = 0;
    map<char, int>::iterator it;

    for (it = mp1.begin(); it != mp1.end(); it++) {
        // 맵의 각 키값에 대해 두 문자열에 있는  
        // 동일한 문자의 수 만큼 same의 값을 올린다. 
        if (mp2.find(it->first) != mp2.end()) {
            same += min(it->second, mp2[it->first]);
        }
    }
    return same;
}

bool isSimilar(string org, string cmp) {
    // 문자열의 구성이 비슷한지 판별한다. 
    int same = 0;
    map<char, int> org_map, cmp_map;
    org_map = getMap(org);
    
    switch (int(cmp.size()-org.size()))
    {
        // 두 문자열의 길이의 차가 1보다 작을 때 
        // 비교를 위해 cmp 문자열의 맵을 생성해준다. 
        // 이때, 두 문자열 중 긴 문자열을 cmpareMap()함수의 첫번째 매개변수로 넣는다. 
    case 0:
    case 1:
        cmp_map = getMap(cmp);
        same = compareMap(cmp_map,org_map);
        break;

    case -1:
        cmp_map = getMap(cmp);
        same = compareMap(org_map, cmp_map);
        break;

    default:
        return false;
    }

    if (max(org.size(),cmp.size())-same == 1 || max(org.size(), cmp.size()) == same) {
        // 문자열의 구성이 같거나 오직 한개의 차이만이 존재한다면 
        // 두 문자열은 비슷하다. 
        return true;
    }

    return false;
}

int main() {
        int n, cnt = 0;
        cin >> n;
        string org, cmp;
        cin >> org;

        for (int j = 0; j < n - 1; j++) {
            cin >> cmp;
            if (isSimilar(org, cmp)) {
                cnt++;
            }
        }

        cout << cnt << '\n';
}