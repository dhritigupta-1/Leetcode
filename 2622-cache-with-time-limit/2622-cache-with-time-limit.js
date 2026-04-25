var TimeLimitedCache = function() {
    this.cache = new Map();
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
    const now = Date.now();
    const exists = this.cache.has(key) && this.cache.get(key).expire > now;
    if(this.cache.has(key)) clearTimeout(this.cache.get(key).timeout);
    const timeout = setTimeout(() => {
        this.cache.delete(key);
    }, duration);
    this.cache.set(key, {
        value,
        expire: now + duration,
        timeout
    });
    return exists;
};

/** 
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function(key) {
    const data = this.cache.get(key);
    if(!data) return -1;
    if(data.expire < Date.now()){
        this.cache.delete(key);
        return -1;
    }
    return data.value;
};

/** 
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function() {
    let count = 0;
    const now = Date.now();
    for(let [key, data] of this.cache){
        if(data.expire > now) count++;
    }
    return count;
};

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */