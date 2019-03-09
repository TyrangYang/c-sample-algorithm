public class LinkedList2019sb{

	private static class Node{ //LinkedList2019sb.Node // inside not point to the outside when use static
		// LinkedList2019sb parent;
		public Node next;
		public int val;
	}
	private Node head;

	public LinkedList2019sb(){
		head = null;
	}

	public void addStart(int v){ // O(1)
		Node temp = new Node();
		temp.val = v;
		temp.next = head;
		head = temp;
	}

	public void addEnd(int v){ //O(n)
		Node temp = new Node();
		temp.val = v;
		temp.next = null;

		if(head == null){
			head = temp;
			return;
		}
		Node p;
		for (p = head; p.next != null; p = p.next){

		}
		p.next = temp;
	}

	public int size(){
		int count = 0;
		Node p;
		for(p = head; p!=null;p = p.next)
			count++;
		return count;
	}

	public int get(int pos){ // O(n)
		Node p = head;
		for(int i = 0; i <pos; i++){
			p = p.next 
		}
		return p.val;
	}

	public int removeStart(){
		Node temp = head;
		head = head.next;
		size--;
		return temp.val;
	}

	public int removeEnd(){
		Node p = head, q = p.next;
		if(q == null){
			int last = head.val;
			head = null;
			return last;
		}

		while(q.next !=null){
			p = q;
			q = q.next;
		}

		p.next = null;
		return q.val;
	}

	public String toString(){
		StringBuilder b = new StringBuilder(this.size()*6);
		for(Node p = head; p != null; p = p.next)
			b.append(p.val).append(' ');
		return b.toString();
	}

	
	public static void main(String[] args) {
		LinkedList2019sb a = new LinkedList2019sb();
		for(int i = 0; i<n ;i++)
			a.addStart(i);
		for(int i = 0; i<n ;i++)
			a.addEnd(i);
		a.removeStart();
		a.removeEnd();
		System.out.println()
	}
}