#include <vector>
#include <unordered_map>
#include <cassert>
#include <iostream>

class LRUCache
{
public:
    LRUCache(int capacity)
        :m_capacity(static_cast<size_t>(capacity))
    {}
    
    int get(int key)
    {
        std::unordered_map<int, std::list<std::pair<int, int>>::iterator>::iterator found_iter = m_map.find(key);
        
        if (found_iter == m_map.end())
        {
            return -1;
        }
        
        updateLRU(found_iter->second);

        return found_iter->second->second;
    }

    void put(int key, int value)
    {
        auto found_iter = m_map.find(key);

        // if found
        if (found_iter != m_map.end())
        {
            found_iter->second->second = value;
            updateLRU(found_iter->second);
            return;
        }

        if (m_capacity == m_map.size())
        {
            auto key_to_del = m_list.back().first;
            m_list.pop_back();
            m_map.erase(key_to_del);
        }

        m_list.emplace_front(key, value);
        m_map[key] = m_list.begin();
    }
private:

    void updateLRU (const std::list<std::pair<int, int>>::iterator& found_iter)
    {
        m_list.splice(m_list.begin(), m_list, found_iter);
    }

    size_t m_capacity;
    std::list<std::pair<int, int>> m_list;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m_map;
};

int main()
{
    LRUCache* lRUCache = new LRUCache(2);
    lRUCache->put(1, 1); 
    lRUCache->put(2, 2);
    std::cout << lRUCache->get(1) << std::endl; 
    lRUCache->put(3, 3);
    std::cout << lRUCache->get(2) << std::endl;   
    lRUCache->put(4, 4);
    std::cout << lRUCache->get(1) << std::endl;   
    std::cout << lRUCache->get(3) << std::endl;   
    std::cout << lRUCache->get(4) << std::endl;
    return 0;
}