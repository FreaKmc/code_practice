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


class LFUCache {
public:
	LFUCache(int capacity) {
		size = capacity;
	}

	int get(int key) {
		if (m.count(key) == 0)
			return -1;
		freq[m[key].second].erase(iter[key]);
		++m[key].second;
		freq[m[key].second].push_back(key);
		iter[key] = --freq[m[key].second].end();
		if (freq[minFre].size() == 0)
			++minFre;
		return m[key].first;
	}

	void put(int key, int value) {
		if (size <= 0) return;
		if (get(key) != -1) {
			m[key].first = value;
			return;
		}
		if (m.size() >= size) {
			m.erase(freq[minFre].front());
			iter.erase(freq[minFre].front());
			freq[minFre].pop_front();
		}
		m[key] = { value, 1 };
		freq[1].push_back(key);
		iter[key] = --freq[1].end();
		minFre = 1;
	}

public:
	int size, minFre;
	unordered_map<int, pair<int, int>> m;
	unordered_map<int, list<int>> freq;
	unordered_map<int, list<int>::iterator> iter;
};