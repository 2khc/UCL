package core;

import java.util.ArrayList;

public class GridFactory {
//	ArrayList<Node> listOfNodes;

	public GridFactory() {

	}

	public ArrayList<Node> create() {
		ArrayList<Node> nodes = new ArrayList<Node>();
		// create nodes
		Node one = new Node(1);
		Node two = new Node(2);
		Node three = new Node(3);
		Node four=new Node(4);
		Node five = new Node(5);
		Node six = new Node(6);
		Node seven = new Node(7);
		Node eight = new Node(8);
		Node nine = new Node(9);
		Node ten = new Node(10);
		Node eleven = new Node(11);
		Node twelve = new Node(12);
		Node thirteen = new Node(13);
		Node fourteen = new Node(14);
		Node fifteen = new Node(15);
		Node sixteen = new Node(16);
		
		// add links
		one.addLinks(two,five);
		two.addLinks(one,three,six);
		three.addLinks(two,four,seven);
		four.addLinks(three,eight);
		five.addLinks(one,six,nine);
		six.addLinks(two,five,seven,ten);
		seven.addLinks(three,eight,six,eleven);
		eight.addLinks(four,seven,twelve);
		nine.addLinks(five,ten,thirteen);
		ten.addLinks(six,nine,eleven,fourteen);
		eleven.addLinks(seven,ten,twelve,fifteen);
		twelve.addLinks(eight,eleven,sixteen);
		thirteen.addLinks(nine,ten,fourteen);
		fourteen.addLinks(ten,thirteen,fifteen);
		fifteen.addLinks(eleven,fourteen,sixteen);
		sixteen.addLinks(twelve,fifteen);
		
		nodes.add(one);
		nodes.add(two);
		nodes.add(three);
		nodes.add(four);
		nodes.add(five);
		nodes.add(six);
		nodes.add(seven);
		nodes.add(eight);
		nodes.add(nine);
		nodes.add(ten);
		nodes.add(eleven);
		nodes.add(twelve);
		nodes.add(thirteen);
		nodes.add(fourteen);
		nodes.add(fifteen);
		nodes.add(sixteen);
		
		return nodes;
	}
}
