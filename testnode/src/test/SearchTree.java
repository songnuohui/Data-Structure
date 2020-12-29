package test;//大话数据结构;

import com.sun.deploy.panel.TreeBuilder;
import org.omg.CORBA.INTERNAL;
import sun.reflect.generics.tree.Tree;

public class SearchTree {

	public TreeNode root;   //记录根节点
	public long size;  //当前结点个数

	/*public TreeNode Bst_Insert(TreeNode treeNode,Integer data){
		if(treeNode==null){
			return new TreeNode(data);
		}
		if(data<treeNode.data){
			return Bst_Insert(treeNode.left,data);
		}
		else if(data>treeNode.data){
			return Bst_Insert(treeNode.right,data);
		}
		return treeNode;
	}*/
	public Boolean addTreeNode(Integer data) {
		if(null==root) {   //根节点是空值的情况下，生成根节点。
			root=new TreeNode(data);
			System.out.println("数据成功插入到平衡二叉树中");
			return true;
		}

		TreeNode treeNode=new TreeNode(data);  //即将被插入的数据
		TreeNode currentNode=root;
		TreeNode parentNode;

		while(true) {
			parentNode=currentNode;
			if(currentNode.data>data) {
				currentNode=currentNode.left;
				if(null==currentNode) { //当前左子节点的父节点为空
					parentNode.left=treeNode;
					treeNode.parent=parentNode;
					System.out.println("数据成功插入到平衡二叉树中");
					size++;
					return true;
				}
			}
			else if(currentNode.data<data) {
				currentNode=currentNode.right;
				if(null==currentNode) {
					parentNode.right=treeNode;
					treeNode.parent=parentNode;
					System.out.println("数据成功插入到平衡二叉树中");
					size++;
					return true;
				}
			}
			/*else {
				System.out.println("输入数据与节点的数据相同");
				size++;
				return true;
			}*/
		}

	}



	public boolean DeleteBst(TreeNode t,Integer key) {
		System.out.println("hello");
		System.out.println(t.data);
		if(t==null) {
			return false;
		}

		else {
			if(key==t.data) {
				return delete1(t);
			}
			else if(key<t.data) {
				return DeleteBst(t.left, key);
			}
			else {
				return DeleteBst(t.right, key);
			}
		}
	}
	public boolean delete1(TreeNode p){
		TreeNode q,s;
		if(p.right==null) {
			q=p;
			p=p.left;
		}
		else if(p.left==null) {
			q=p;
			p=p.right;
		}
		else {
			q=p;
			s=p.left;
			while(s.right.right!=null) {
				q=s;
				s=s.right;

			}
			p.data=s.data;
			if(q!=p) {
				q.right=s.left;


			}
			else {
				q.left=s.left;
			}
		}
		return true;
	}

	public  TreeNode findMin(TreeNode treeNode){
		if(treeNode!=null){
			while(treeNode.left!=null){
				treeNode=treeNode.left;
			}
		}
		return treeNode;
	}
	public TreeNode findMax(TreeNode treeNode){
		if(treeNode!=null){
			while(treeNode.right!=null){
				treeNode=treeNode.right;
			}
		}
		return treeNode;
	}
	public TreeNode delete(TreeNode p ,Integer key) {
		if(p==null){
			return null;
		}
		int compareResult=key.compareTo(p.data);

		/**找到需要删除的那个结点**/
		if(compareResult<0){
			p.left=delete(p.left,key);
		}
		else if(compareResult>0){
			p.right=delete(p.right,key);
		}
		/**该节点含有左右子树的话，删除该节点的话就需要从右子树中找到最小那个值代替
		 * 好像也可以从左子树中找到最大值来代替
		 * **/
		else if(p.left!=null&&p.right!=null){
			p.data=findMax(p.left).data;
			p.left=delete(p.left,p.data);
		}
		/*else if(p.left!=null&&p.right!=null){
			p.data=findMin(p.right).data;
			p.right=delete(p.right,p.data);
		}*/
		/**如果只有一边有就直接等于其下一个结点**/
		else{
			p=(p.left!=null)?p.left:p.right;
		}
		return p;
	}



	public TreeNode findTreeNode(Integer data) {
		if(null==root) {
			return null;
		}
		TreeNode current=root;
		while(current!=null) {
			if(current.data>data) {
				current=current.left;
			}
			else if(current.data<data) {
				current=current.right;
			}
			else {
				return current;
			}
		}
		return null;
	}

}
