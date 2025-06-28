// Here mp is the unordered_map where the leaf to parent is stored


class Solution {
public:
    bool isBSTHelper(TreeNode* root, long minVal, long maxVal) {
        if (root == NULL) return true;
        if(root->val <= minVal || root->val >= maxVal) return false;
        return isBSTHelper(root->left, minVal, root->val) && isBSTHelper(root->right, root->val, maxVal);
    }
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int, TreeNode*> mp;
//  trees -> parent
        unordered_map<TreeNode*,TreeNode*> par;
        // inserting values in parent
        for(auto t : trees){
            par[t] = t;
        }
        
        // inserting the values in mp
        for(int i =0; i< trees.size(); i++){
            TreeNode* tmp = trees[i];
            if(tmp->left){ 
                if(mp.find(tmp->left->val) == mp.end())
                    mp[tmp->left->val] = tmp;
                else return NULL;
            }
            if(tmp->right){ 
                if(mp.find(tmp->right->val) == mp.end())
                    mp[tmp->right->val] = tmp;
                else return NULL;
            }
        }
        for(int i = 0; i< trees.size(); i++){
            TreeNode* tmp = trees[i];
            if(mp.find(tmp->val) != mp.end()){
                TreeNode* root = mp[tmp->val];
                if(root->right && root->right->val == tmp->val){
                    int check = INT_MAX;
                    if(tmp->left){
                        check = tmp->left->val;
                    }
                    if(check > root->val){
                        root->right = tmp;
                        par[tmp] = par[root];
                        mp.erase(tmp->val);
                    }else{
                        return NULL;
                    }
                }
                else if(root->left && root->left->val == tmp->val){
                    int check = 0;
                    if(tmp->right){
                        check = tmp->right->val;
                    }
                    if(check< root->val){
                        root->left = tmp;
                        par[tmp] = par[root];
                        mp.erase(tmp->val);
                    }else{
                        return NULL;
                    }
                }
            }
        }
        vector<TreeNode*> ans;
        for(auto t : par){
            if(t.first == t.second){
                ans.push_back(t.first);
            }
        }
        if(ans.size() == 1){ 
            if(isBSTHelper(ans[0],LONG_MIN, LONG_MAX))
                return ans[0];
        }
        return NULL;
    }
};