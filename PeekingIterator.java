
import java.util.Iterator;
import java.util.NoSuchElementException;

class PeekingIterator implements Iterator<Integer> {

    Iterator<Integer> iterator;
    Integer nextLoaded;

    public PeekingIterator(Iterator<Integer> iterator) {
        this.iterator = iterator;
        this.nextLoaded = iterator.hasNext() ? iterator.next() : null;
    }

    public Integer peek() {
        if (!hasNext()) {
            throw new NoSuchElementException();
        }
        return nextLoaded;
    }

    @Override
    public Integer next() {
        if (!hasNext()) {
            throw new NoSuchElementException();
        }

        int temp = nextLoaded;
        nextLoaded = null;

        if (iterator.hasNext()) {
            nextLoaded = iterator.next();
        }
        return temp;
    }

    @Override
    public boolean hasNext() {
        return nextLoaded != null;
    }
}
