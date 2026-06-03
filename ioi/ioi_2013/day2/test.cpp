set<pair<int,int>>s;
        vector<int>nbrr;
        set<pair<int,int>>cand;
        vector<int>crr=arr;
        for(int i = sz(vals)-1; i>=0; i--){
            while(sz(crr) && crr.back()>=vals[i].first){
                crr.pop_back();
                s.insert({0,sz(crr)});
            }
            if(sz(s)==0){
                nbrr.push_back(vals[i].second);
                continue;
            }
            auto it = s.begin();
            auto [val,idx] = (*it);
            if(val>=x){
                it = cand.begin();
                nbrr.push_back((*it).first);
                cand.erase(it);
                cand.insert({vals[i].second,vals[i].first});
            }else{
                s.erase(it);
                cand.insert({vals[i].second,vals[i].first});
                s.insert({val+1,idx});
            }
        }
        int ansv=oned(nbrr,brr);
        if(ansv==-1) return 0;
        return ansv<=x;