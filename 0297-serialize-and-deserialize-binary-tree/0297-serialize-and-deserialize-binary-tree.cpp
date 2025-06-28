/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void encode(TreeNode* node, string path, vector<string>& parts) {
        if (!node) return;
        parts.push_back(path + ":" + to_string(node->val));
        encode(node->left, path + "0", parts);
        encode(node->right, path + "1", parts);
    }

    string serialize(TreeNode* root) {
        vector<string> parts;
        encode(root, "", parts);
        string result;
        for (int i = 0; i < parts.size(); ++i) {
            result += parts[i];
            if (i < parts.size() - 1) result += ",";
        }
        return result;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        unordered_map<string, int> pathMap;
        stringstream ss(data);
        string token;
        while (getline(ss, token, ',')) {
            int sep = token.find(':');
            string path = token.substr(0, sep);
            int val = stoi(token.substr(sep + 1));
            pathMap[path] = val;
        }

        TreeNode* root = new TreeNode(pathMap[""]);
        for (auto& [path, val] : pathMap) {
            if (path.empty()) continue;
            TreeNode* curr = root;
            for (int i = 0; i < path.size(); ++i) {
                if (path[i] == '0') {
                    if (!curr->left) curr->left = new TreeNode(0);
                    curr = curr->left;
                } else {
                    if (!curr->right) curr->right = new TreeNode(0);
                    curr = curr->right;
                }
            }
            curr->val = val; // assign value once the full path is reached
        }
        return root;
    }
};