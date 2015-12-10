package core;

import java.util.ArrayList;

public class Main {

	public static void main(String[] args) {
		GridFactory gridFactory = new GridFactory();
		ArrayList<Node> nodes = gridFactory.create();

		System.out.println("Hello World");
		String input = System.console().readLine();
	}

	private ArrayList<Node> initNodes(int[] startingNodes, ArrayList<Node> nodes) {

		for (int i = 1; i <= startingNodes.length; i++) {
			nodes.get(startingNodes[i - 1]).setActive(true);
		}
		return nodes;
	}

	private static void BreadthFirstSearch(ArrayList<Node> nodes, int v) {

		for (int n = 0; n < G.size(); n++) {
			// n.distance = Integer.MAX_VALUE;
		}

	}

}
