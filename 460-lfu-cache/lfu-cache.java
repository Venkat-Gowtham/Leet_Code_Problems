class LFUCache {
    private Map<Integer,Pair<Integer,Integer>>cache;
    private Map<Integer,LinkedHashSet<Integer>>fre;
    private int  minf;
    private int capacity;
    public LFUCache(int capacity) {
        cache = new HashMap<>();
        this.capacity = capacity;
        minf = 0;
        fre = new HashMap<>();
    }
    public void insert(int key, int frequency,int value){
        cache.put(key, new Pair<>(frequency, value));
        fre.putIfAbsent(frequency, new LinkedHashSet<>());
        fre.get(frequency).add(key);
    }
    public int get(int key) {
        Pair<Integer,Integer>frev = cache.get(key);
        // no key exists
        if(frev == null){
            return -1;
        }
        final int frequency = frev.getKey();
        final Set<Integer>keys = fre.get(frequency);
        keys.remove(key);
        if(keys.isEmpty()){
            fre.remove(frequency);
            if(minf == frequency)++minf;
        }

        final int value = frev.getValue();
        insert(key,frequency+1,value);
        return value;

    }
    
    public void put(int key, int value) {
        if(capacity<=0) return ;
        Pair<Integer,Integer>frev = cache.get(key);
        if(frev != null){
            cache.put(key,new Pair<>(frev.getKey(),value));
            get(key);
            return ;
        }
        if(capacity == cache.size()){
            final Set<Integer>keys = fre.get(minf);
            final int keyToDelete = keys.iterator().next();
            cache.remove(keyToDelete);
            keys.remove(keyToDelete);
            if(keys.isEmpty()){
                fre.remove(minf);
            }
        }
        minf = 1;
        insert(key,1,value);

    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */