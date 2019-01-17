## overall design  
`vector<int> tweets`: store all the tweets posted by users.  
`unordered_map<int, vector<int>> userTweets`: a hashmap that maps the userId to the array of tweets by this user. The array stores the position of this tweet in tweets array, like a pointer points to that tweet in tweets array. The most recent tweet is at the back of the user tweets array.  
`unordered_map<int, unordered_set<int>> userFollows`: a hashmap that maps the userId to the hashset of this user's followees, i.e, other users this user follows.  

## postTweet  
(1) add the tweet to the back of userTweets array, but not the tweetId, instead should be the size of current tweets array.
(2) add the tweet to all tweets: `tweets.push_back(tweetId)`.

## getNewsFeed  
Use a max heap to store the position of this user's and her followees' latest tweets in all tweets and the corresponding userId. `priority_queue<pair<int, int>> heap`.  
Use a hashmap to store the current position in userTweets array. `unordered_map<int, int> position` which maps the userId to the current position in userTweets array.  
(1) Check whether the user and her followees have tweets. If so, push everyone's latest tweet with corresponding userId to the heap. Map the userId to the last position in userTweets.  
(2) In each iteration, pop the top of the heap. Get the userId and subtract `position[userId]` by 1. Get the next most recent tweet of this user if any and push it to heap.  
(3) Stop iteration either no tweets any more or have got 10 tweets.  

## follow  
I think the operation is invalid if followerId == followeeId.  
For a valid operation, simply insert the followeeId to userFollows.  

## unfollow  
First check whether the followerId has any followees and then whether the followeeId is in the followerId's followees' set.
