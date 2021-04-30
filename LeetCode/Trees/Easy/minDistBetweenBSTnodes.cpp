// Solution 1:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
	// int minn = INT_MAX;
	vector<int> arr;
public:
	void print(vector<int> arr){
		for(auto x:arr){
			cout<<x<<" ";
		}
	}
	void prepareArr(TreeNode* root){
		if(!root) return;
		arr.push_back(root->val);
		prepareArr(root->left);
		prepareArr(root->right);
	}

    int minDiffInBST(TreeNode* root) {
		if(!root) return 0;
		prepareArr(root);
		sort(arr.begin(), arr.end());
		int minn = INT_MAX;
		for(int i=1; i<arr.size(); i++){
			if(abs(arr[i]-arr[i-1])<minn) minn=arr[i]-arr[i-1];
		}
		// print(arr);
		return minn;
    }
};

