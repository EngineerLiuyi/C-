2020/7/13
/**************************************************
关于迭代器的运用，同时遍历一遍c/cpp语言中相关的容器，内容
来自huahua的youtube教程和cppreference.com上面的资料
**************************************************/
Container 			Iterator 			direction 
vector 				Random access			/data struct/vector.cpp
deque				Random access 			/data struct/deque.cpp
list 				Bidirectional 			/data struct/list.cpp
map/multimap/set/multiset	Bidirectional(const key)	/data struct/map.cpp
unordered_set/ unordered_map	Forward(const key)		/data struct/map.cpp
stack 				Not supported 
queue 				Not supported 
priority_queue 			Not supported 
