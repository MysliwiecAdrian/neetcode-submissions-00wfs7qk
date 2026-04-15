struct Tweet{
    int id;
    int timePosted;

    bool operator<(const Tweet& other) const {
        return this->id < other.id; 
    }
};

struct User{
    int id;
    set<int> following;
    vector<Tweet> tweets;
};

class Twitter {
private:
    map<int, User> users;
    int time = 0;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        auto& tweets = users[userId].tweets;
        tweets.push_back({tweetId, time});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue< pair<int, Tweet>, vector<pair<int, Tweet>>, greater<pair<int, Tweet>> > recent;

        // iterate through userId's tweets
        // iterate through userId following tweets
        // when the size > 10 i will have to pop to get rid of oldest tweet
        // pushing onto the pq will be the [time, Tweet]
        auto& tweets = users[userId].tweets;
        
        addTweets(tweets, recent);

        auto& following = users[userId].following;

        for (int id : following){
            auto& followingTweets = users[id].tweets;
            addTweets(followingTweets, recent);
        }
        
        while (!recent.empty()){
            res.push_back(recent.top().second.id);
            recent.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId){
            users[followerId].id = followerId;
            auto& following = users[followerId].following;
            following.insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        auto& following = users[followerId].following;
        following.erase(followeeId);
    }

    void addTweets(auto& tweets, priority_queue< pair<int, Tweet>, vector<pair<int, Tweet>>, greater<pair<int, Tweet>> >& recent){
        for (auto& t : tweets){
            recent.push({t.timePosted, t});
            if (recent.size() > 10){
                recent.pop();
            }
        }
    }
};
