class Solution {
    void Func(int[] nums, List<Integer> temp, List<List<Integer>> res, boolean[] used, int start)
    {
        if(temp.size() == nums.length)
        {
            res.add(new ArrayList<>(temp));
            return;
        }
        for(int i=0; i<nums.length; i++)
        {
            if(used[i]) continue;
            if(i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;
            used[i] = true;
            temp.add(nums[i]);
            Func(nums, temp, res, used, i+1);
            temp.remove(temp.size() - 1);
            used[i] = false;
        }
    }
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        boolean used[] = new boolean[nums.length];
        Arrays.sort(nums);
        Func(nums, new ArrayList<>(), res, used, 0);
        return res; 
    }
}