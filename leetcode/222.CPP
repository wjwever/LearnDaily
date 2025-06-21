class Solution {
    public int countNodes(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int count = 0;
        int leftH = getHeight(root.left);
        while (root != null) {
            int rightH = getHeight(root.right);
            if (leftH == rightH) {
                // 此时左子树一定满
                count += (1 << leftH);
                root = root.right;
            } else {
                // 此时右子数一定满
                count += (1 << rightH);
                root = root.left;
            }
            // 左子树高度只需要-1
            leftH--;
        }
        return count;
    }

    private int getHeight(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int height = 0;
        while (root != null) {
            height++;
            root = root.left;
        }
        return height;
    }
}
