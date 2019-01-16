#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>
using namespace std;

class Twitter {
private:
    unordered_map<int, vector<int> > userTweets;
    unordered_map<int, unordered_set<int> > userFollows;
    vector<int> tweets;
public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets.push_back(tweetId);
        userTweets[userId].push_back(tweets.size() - 1);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        unordered_map<int, int> position;
        priority_queue<pair<int, int> > heap;
        
        if(userTweets.count(userId)) {
            position[userId] = userTweets[userId].size() - 1;
            heap.push(make_pair(userTweets[userId].back(), userId));
        }

        if(userFollows.count(userId)) {
            unordered_set<int> followees = userFollows[userId];
            for(unordered_set<int>::iterator it = followees.begin(); it != followees.end(); it++) {
                if(userTweets.count(*it)) {
                    position[*it] = userTweets[*it].size() - 1;
                    heap.push(make_pair(userTweets[*it].back(), *it));
                } 
            }
        }
        
        
        vector<int> result;
        while(!heap.empty() && result.size() < 10) {
            int posInTweets = heap.top().first, user = heap.top().second;
            heap.pop();
            result.push_back(tweets[posInTweets]);
            if(position[user] > 0) {
                position[user]--;
                heap.push(make_pair(userTweets[user][position[user]], user));
            }
        }
        return result;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) {
            return;
        }
        userFollows[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(userFollows.count(followerId) &&
          userFollows[followerId].count(followeeId)) {
            userFollows[followerId].erase(userFollows[followerId].find(followeeId));
        }
    }
};

int main() {
	vector<int> res;
	Twitter twitter;
	twitter.postTweet(1, 5);
	res = twitter.getNewsFeed(1);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
	cout << endl;
	twitter.follow(1, 2);
	twitter.postTweet(2, 6);
	res = twitter.getNewsFeed(1);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
	cout << endl;
	twitter.unfollow(1, 2);
	res = twitter.getNewsFeed(1);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
	cout << endl;
	return 0;
}