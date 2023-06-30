
# #  * Your Twitter object will be instantiated and called as such:
#  int main(){
#     Twitter* obj = new Twitter();
#     obj->postTweet(2,5);
#     vector<int> param_2 = obj->getNewsFeed(2);
#     obj->follow(1,2);
#     cout<<obj->followers[1].size();
#     obj->unfollow(1,2);
#     cout<<obj->followers[1].size();
#  }

#desigining twitter
#for follow  - use map ir hashmap to map followers of a userid and mapping is done to a list of followers using List
#FOR unfollow = TO remove a followers from a list most efficient is to use HAshset that can perform remove and insertion in O(1) time
#THUS using hashset to store followers is best approach

#for posttweet initailly hashmap i.e. userid->list of post tweetid
#Since addding tweetid to list is in O(1) time Use lists

#for get 10 recent tweets from user's followers 
#i.e. get 10 reccent tweets from user's followers to get the user;s feed

#userId -> list of tweet id but for one userId
# one user follow multipe people so we have to get 10 most recent tweets made among all its followers by tracking time when tweet osted by followers
#Thus instead to map userid-> list of tweet id
#DO map userId -> pair[count,TweetId] wehere count  = 0 initially then goes from 0 to -1 -2 ...  -ve indexing bcoz to use min heap 

class Twitter:

    def __init__(self):
        self.count = 0 #count is used as key which is unique to each tweet acroos all its users
        self.tweetMap = dict(list) #userId -> list of [count,tweetIds]
        self.followMap = dict(set) #userId -> set of followeeId
    #if not to use dictionaries use hashmaps to implement

    #->None => return type void
    def postTweet(self,userId: int,tweetId: int) -> None:
        self.tweetMap[userId].append([self.count, tweetId])
        self.count -= 1

    def getNewsFeed(self,userId :int) ->List[int]:
        res = [] #ordered tweetids staeting from most recent tweetId
        minHeap = []

        self.followMap[userId].add[userId]#incluede useer himself in his follower map of his foloowMap
        #go through all followees of user

        for followeeId in self.followMap[userId]:
            if followeeId in self.tweetMap:
                index = len(self.tweetMap[followeeId]) -1  #last tweet'index of this follower
                count, tweetId = self.tweetMap[followeeId][index]
                minHeap.append([count , tweetId, followeeId, index-1])
                #return count and tweetid for result res and also return followeeid so we can access its other previous tweets using index of its last tweet
                #now heapify the list returned evertime
        heapq.heapify(minHeap)
        while minHeap and len(res)<10:
            count,tweetId,followeeId,index = heapq.heappop(minHeap)
            res.append(tweetId)

            if index>=0:
                count , tweetId = self.tweetMap[followeeId][index]
                heapq.heappush(minHeap,[count,tweetId,followeeId,index-1])
        return res

    def follow(self,followerId:int, followeeId: int) -> None:

        self.followMap[followerId].add(followeeId)
        #i to use hashset first iniliase an empty set then add followeeId
        #Using self.followMap[followerId] = set

    def unfollow(self,followerId: int, followeeId: int) -> None:

        if followeeId in self.followMap[followeeId]:
            self.followMap[followerId].remove(followeeId)



