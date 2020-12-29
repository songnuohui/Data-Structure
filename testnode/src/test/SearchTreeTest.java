package test;//大话数据结构;

import java.util.Scanner;

public class SearchTreeTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		SearchTree tree=new SearchTree();
		tree.addTreeNode(50);
		tree.addTreeNode(20);
		tree.addTreeNode(80);
		//tree.addTreeNode(20);
		tree.addTreeNode(60);
		tree.addTreeNode(10);
		tree.addTreeNode(30);
		//tree.addTreeNode(30);
		tree.addTreeNode(70);
		tree.addTreeNode(90);
		tree.addTreeNode(100);
		tree.addTreeNode(40);

		System.out.print("删除前：");
		TreeOrder.medOrderMethodOne(tree.root);
		tree.delete(tree.root, 40);
		System.out.println();
		System.out.print("删除后：");
		TreeOrder.medOrderMethodOne(tree.root);
	}

}
