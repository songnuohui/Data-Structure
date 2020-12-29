package test;//大话数据结构;

public class TreeNode {

	public Integer data;   //存储该结点的数据

	public TreeNode parent;  //该结点的父节点

	public TreeNode left;   //该结点的左子节点

	public TreeNode right;   //该节点的右子节点

	public TreeNode(Integer data) {  //为该结点赋值
		this.data=data;
	}

	public String toString() {
		return "TreeNode [data="+data+"]";
	}

}
