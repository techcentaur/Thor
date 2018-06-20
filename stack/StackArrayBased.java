import java.util.EmptyStackException;

interface Stack{
    public void push(Object o) throws EmptyStackException;
    public Object pop() throws EmptyStackException;
    public boolean isEmpty();
    public int size();
    public Object top() throws EmptyStackException;
}

class StackArrayBased implements Stack
{

    private int maxSize;
    private Object[] array;
    private int index;

    //Initialize the stack constructor with a fixed size array @params: newsize - size of the array
    public StackArrayBased(int newsize) {
        maxSize = newsize;
        array = new Object[maxSize];
        index = -1;
    }

    @Override
    //pushes the element on the top of the array;
    public void push(Object o) {
        if (index != maxSize-1) array[++index] = o;
    }

    @Override
    //pop and return the element on the top;
    public Object pop() {
        Object popped;

        if (index != -1){
            popped = array[index--]; //take top element, decrement index
        }
        else throw new EmptyStackException();

        return popped;
    }

    @Override
    //checks if stack is empty
    public boolean isEmpty() {
        return index == -1;
    }

    @Override
    public int size() {
        return index + 1;
    }

    @Override
    public Object top() {
        if (index != -1) return array[index];
        else throw new EmptyStackException();
    }

    public static void main(String[] args){
        StackArrayBased s = new StackArrayBased(10);
        s.push(10);
        s.push(3);
        s.push(4);
        System.out.println(s.top());
        s.pop();
        System.out.println(s.top());
        System.out.println(s.size());
    }

}
