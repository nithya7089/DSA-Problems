struct RangeMaxTree {
    int size;
    vector<int> nodes;

    RangeMaxTree(const vector<int>& input) {
        size = input.size();
        nodes.resize(4 * size, -1);
        constructTree(input, 1, 0, size - 1);
    }

    void constructTree(const vector<int>& data, int nodeIndex, int left, int right) {
        if(left == right) {
            nodes[nodeIndex] = data[left];
            return;
        }
        
        int middle = left + (right - left) / 2;
        constructTree(data, nodeIndex * 2, left, middle);
        constructTree(data, nodeIndex * 2 + 1, middle + 1, right);
        nodes[nodeIndex] = max(nodes[nodeIndex * 2], nodes[nodeIndex * 2 + 1]);
    }

    void modifyValue(int nodeIndex, int left, int right, int idx) {
        if(left == right) {
            nodes[nodeIndex] = INT_MIN;
            return;
        }
        
        int middle = left + (right - left) / 2;
        if(idx <= middle) {
            modifyValue(nodeIndex * 2, left, middle, idx);
        } else {
            modifyValue(nodeIndex * 2 + 1, middle + 1, right, idx);
        }
        nodes[nodeIndex] = max(nodes[nodeIndex * 2], nodes[nodeIndex * 2 + 1]);
    }

    int searchFirstValid(int nodeIndex, int left, int right, int target) {
        if(nodes[nodeIndex] < target) return -1;
        
        if(left == right) {
            return left;
        }

        int middle = left + (right - left) / 2;
        int leftSubtreeMax = nodes[nodeIndex * 2];
        
        if(leftSubtreeMax >= target) {
            return searchFirstValid(nodeIndex * 2, left, middle, target);
        }
        return searchFirstValid(nodeIndex * 2 + 1, middle + 1, right, target);
    }

    int findFirstValidPosition(int target) {
        return searchFirstValid(1, 0, size - 1, target);
    }

    void removeValue(int idx) {
        modifyValue(1, 0, size - 1, idx);
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& items, vector<int>& containers) {
        int ans = 0;
        RangeMaxTree tree(containers);
        for(int item : items) {
            int idx = tree.findFirstValidPosition(item);
            if(idx == -1) {
                ans++;
                ans+=1;
            } else {
                tree.removeValue(idx);
            }
        }
        return ans/2;
    }
};