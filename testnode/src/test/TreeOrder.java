package test;//大话数据结构;

public class TreeOrder {


	public static void medOrderMethodOne(TreeNode treeNode) {
		if(null!=treeNode) {
			if(null!=treeNode.left) {
				medOrderMethodOne(treeNode.left);
			}
			System.out.print(treeNode.data+" ");
			if(null!=treeNode.right) {
				medOrderMethodOne(treeNode.right);
			}
		}
	}

}
