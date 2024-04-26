/*
1146. 快照数组
中等

实现支持下列接口的「快照数组」- SnapshotArray：

SnapshotArray(int length) - 初始化一个与指定长度相等的 类数组 的数据结构。初始时，每个元素都等于 0。
void set(index, val) - 会将指定索引 index 处的元素设置为 val。
int snap() - 获取该数组的快照，并返回快照的编号 snap_id（快照号是调用 snap() 的总次数减去 1）。
int get(index, snap_id) - 根据指定的 snap_id 选择快照，并返回该快照指定索引 index 的值。
*/

#ifndef _BINARYSEARCH_LEETCODE1146_H_
#define _BINARYSEARCH_LEETCODE1146_H_


class SnapshotArray {
private:
    int len;
    int count;
    vector<int> curr;
    vector<vector<pair<int, int>>> snaps;
    int find(vector<pair<int, int>>& snap, int target){
        int left = 0;
        int right = snap.size()-1;
        int mid = 0;
        while(left < right){
            mid = left + (right - left)/2;
            if(snap[mid].first == target){
                return snap[mid].second;
            }else if(snap[mid].first < target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return snap[left].first <= target? snap[left].second: snap[mid].second;
    }
public:
    SnapshotArray(int length):len(length), count(0), curr(length, 0), snaps(length){
    }
    
    void set(int index, int val) {
        curr[index] = val;
    }
    
    int snap() {
        for(int i = 0; i<len; ++i){
            if(snaps[i].empty() || snaps[i].back().second != curr[i]){
                snaps[i].emplace_back(count, curr[i]);
            }
        }
        count ++;
        return count - 1;
    }
    
    int get(int index, int snap_id) {
        return find(snaps[index], snap_id);
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

void test1146() {
    SnapshotArray* obj = new SnapshotArray(3);
    obj->set(0, 5);
    obj->snap();
    obj->set(0, 6);
    obj->get(0, 0);
    delete obj;

    // ["SnapshotArray","snap","snap","set","snap","get","set","get","snap","get"]
    // [[1],[],[],[0,4],[],[0,1],[0,12],[0,1],[],[0,3]]
    obj = new SnapshotArray(1);
    obj->snap();
    obj->snap();
    obj->set(0, 4);
    obj->snap();
    cout << obj->get(0, 1) << endl;
    obj->set(0, 12);
    cout << obj->get(0, 1) << endl;
    obj->snap();
    cout << obj->get(0, 3) << endl;
    delete obj;
    obj = nullptr;

    // ["SnapshotArray","set","snap","set","snap","snap","set","snap","get","snap","snap","set","snap","get","set","snap","set","set"]
    // [[2],[0,8],[],[0,9],[],[],[0,11],[],[1,1],[],[],[0,1],[],[0,1],[0,0],[],[0,3],[1,13]]
    obj = new SnapshotArray(2);
    obj->set(0, 8);
    obj->snap();
    obj->set(0, 9);
    obj->snap();
    obj->snap();
    obj->set(0, 11);
    obj->snap();
    cout << obj->get(1, 1) << endl;
    obj->snap();
    obj->snap();
    obj->set(0, 1);
    obj->snap();
    cout << obj->get(0, 1) << endl;
    obj->set(0, 1);
    obj->set(0, 0);
    obj->snap();
    obj->set(0, 3);
    obj->set(1, 13);
    delete obj;
    obj = nullptr;

}


#endif // !_BINARYSEARCH_LEETCODE1146_H_