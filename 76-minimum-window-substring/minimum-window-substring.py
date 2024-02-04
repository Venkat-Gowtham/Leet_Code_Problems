class Solution:
    def minWindow(self, s: str, t: str) -> str:
        l=[0]*26
        u=[0]*26
        lv=[0]*26
        uv=[0]*26
        
        mp={}
        mt={}
        res=1000000
        for i in t:
            if i not in mp:
                mp[i]=1
                if i.islower():
                    l[ord(i)-97]=1
                else:
                    u[ord(i)-65]=1
            else:
                mp[i]+=1
        i=0
        j=0
        f=0
        ma=len(mp)
        n=len(s)
        x=-1
        y=-1
        # print(mp[])
        while j<n:
            #storing lowr case and ther freq and vis in l list
            # print(l[0])
            if s[j].islower() and l[ord(s[j])-97]==1:
                if s[j] not in mt:
                    mt[s[j]]=1
                else:
                    mt[s[j]]+=1
                # print(mt[s[j]])
                print(j)
                if(j==3):
                    print(mt[s[j]],mp[s[j]],lv[ord(s[j])-97],end=" ")
                if mt[s[j]]>=mp[s[j]] and lv[ord(s[j])-97]==0:
                    
                    lv[ord(s[j])-97]=1
                    f+=1
            #storing uppr case and ther freq and vis in u list
            elif s[j].isupper() and u[ord(s[j])-65]==1:
                if s[j] not in mt:
                    mt[s[j]]=1
                else:
                    mt[s[j]]+=1
                if mt[s[j]]>=mp[s[j]] and uv[ord(s[j])-65]==0:
                    uv[ord(s[j])-65]=1
                    f+=1
            if f==ma:
                print("hi")
                while f==ma:
                    if(j-i+1<=res):
                        x=i
                        y=j
                        res=j-i+1
                    if s[i] in mt:
                        mt[s[i]]-=1
                        if mt[s[i]]<mp[s[i]]:
                            f-=1
                            if s[i].islower():
                                lv[ord(s[i])-97]=0
                            else:
                                uv[ord(s[i])-65]=0
                    i+=1
            j+=1
        if x==-1 and y==-1:
            return ""
        return s[x:y+1]
            






        
        