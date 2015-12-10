package core;

import java.util.ArrayList;

public class Node {
	ArrayList<Node> linkedNodes;
	boolean active = false;
	int key;
	public Node(int key){
//		this.connectedNodes = connectedNodes;
		
		this.key = key;
		this.active = false;
	}
	
	public void addLinks (Node... nodes){
		for (int n=0;n<nodes.length;n++)
		this.linkedNodes.add(nodes[n]);
	}
	
	public void setActive(boolean value){
		this.active = value;
	}
	
	public boolean getActive(){
		return this.active;
	}
	
	public int getKey(){
		return this.key;
	}
}	
