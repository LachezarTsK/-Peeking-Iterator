
/**
 * @param {Iterator} iterator
 */
var PeekingIterator = function (iterator) {
    this.iterator = iterator;
    this.nextLoaded = iterator.hasNext() ? iterator.next() : null;
};

/**
 * @return {number}
 */
PeekingIterator.prototype.peek = function () {
    if (!this.hasNext()) {
        throw "No Such Element Exception.";
    }
    return this.nextLoaded;
};

/**
 * @return {number}
 */
PeekingIterator.prototype.next = function () {
    if (!this.hasNext()) {
        throw "No Such Element Exception.";
    }

    let temp = this.nextLoaded;
    this.nextLoaded = null;

    if (this.iterator.hasNext()) {
        this.nextLoaded = this.iterator.next();
    }

    return temp;
};

/**
 * @return {boolean}
 */
PeekingIterator.prototype.hasNext = function () {
    return this.nextLoaded !== null;
};

/**
 *  This is the Iterator's API interface. 
 *  It is implemented internally by leetcode.com.
 *  It should not be included in the code, when running it on the website.
 *  
 * function Iterator() {
 *    @return {number}
 *    this.next = function() { // return the next number of the iterator
 *       ...
 *    }; 
 *
 *    @return {boolean}
 *    this.hasNext = function() { // return true if it still has numbers
 *       ...
 *    };
 * };
 */
