struct DoubleLinkedNode{
	int key;
	int value;
	DoubleLinkedNode *prev;
	DoubleLinkedNode *next;
	DoubleLinkedNode():key(0),value(0),prev(nullptr),next(nullptr){}
	DoubleLinkedNode(int k,int v):key(k),value(v),prev(nullptr),next(nullptr){}
};
class LRUCache {
private:
	unordered_map<int,DoubleLinkedNode*>cache;//编号到链表节点的映射
	DoubleLinkedNode *head;//头结点，本身不存数
	DoubleLinkedNode *tail;//尾结点，本身不存数
	int size;//使用的容量
	int capacity;//总容量
public:
    LRUCache(int capacity) {
		this->capacity=capacity;
		head=new DoubleLinkedNode();
		tail=new DoubleLinkedNode();
		head->next=tail;
		tail->prev=head;
		size=0;
    }
    
	void addToHead(DoubleLinkedNode *now){//新来的放到头部
		now->prev=head;
		now->next=head->next;
		head->next->prev=now;
		head->next=now;
	}
	void moveToHead(DoubleLinkedNode *now){//刚访问过的移到头部
		removedNode(now);
		addToHead(now);
	}
	void removedNode(DoubleLinkedNode *now){//删除节点
		now->prev->next=now->next;
		now->next->prev=now->prev;
	}
	DoubleLinkedNode *removeTail(){//删掉尾部
		DoubleLinkedNode *p=tail->prev;
		removedNode(p);
		return p;
	}

    int get(int key) {
		if(!cache.count(key)){
			return -1;
		}
		DoubleLinkedNode *now=cache[key];
		moveToHead(now);
		return now->value;
    }
    
    void put(int key, int value) {
		if(!cache.count(key)){//不存在key
			DoubleLinkedNode *now=new DoubleLinkedNode(key,value);
			cache[key]=now;//建立映射
			addToHead(now);
			size++;
			if(size>capacity){
				DoubleLinkedNode *removedNode = removeTail();
				cache.erase(removedNode->key);
				delete removedNode;
				size--;
			}
		}
		else{
			DoubleLinkedNode *now=cache[key];
			now->value=value;
			moveToHead(now);
		}
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */