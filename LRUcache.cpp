class LRUCache {
public:
	LRUCache(int capacity) {
		size = capacity;
	}

	int get(int key) {
		auto it = mp.find(key);
		if (it == mp.end())
			return -1;
		mp[key] = fresh(it->second);
		return mp[key]->second;
	}

	void put(int key, int value) {
		auto it = mp.find(key);
		if (it != mp.end()) {
			mp[key] = fresh(it->second);
			mp[key]->second = value;
		}
		else {
			if (mp.size() < size) {
				mp[key] = cache.insert(cache.end(), { key, value });
			}
			else {
				mp.erase(cache.front().first);
				cache.pop_front();
				mp[key] = cache.insert(cache.end(), { key, value });
			}
		}
	}

	list<pair<int, int>>::iterator fresh(list<pair<int, int>>::iterator it){
		auto res = cache.insert(cache.end(), *it);
		cache.erase(it);
		return res;
	}

public:
	list<pair<int, int>> cache;
	unordered_map<int, list<pair<int, int>>::iterator> mp;
	int size;

};