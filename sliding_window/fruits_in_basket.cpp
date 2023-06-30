map<int,int> mp;

        int i=0,j=0,n=fruits.size();

        int size=0;

        while(j<n){

            mp[fruits[j]]++;

            while(mp.size()>2){

                mp[fruits[i]]--;

                if(mp[fruits[i] ]==0){

                    mp.erase(fruits[i]);

                }

                i++;

            }

            size=max(size,j-i+1);

            j++;

        }

        return size; 