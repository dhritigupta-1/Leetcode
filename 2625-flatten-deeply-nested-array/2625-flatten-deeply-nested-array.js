/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {
    const result = [];
    function helper(current, depth){
        for(let el of current){
            if(Array.isArray(el) && depth > 0) helper(el, depth-1);
            else result.push(el);
        }
    }
    helper(arr,n);
    return result;
};