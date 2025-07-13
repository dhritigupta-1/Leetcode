class Solution {
    void Func(int[] nums, int target, List<List<Integer>> res, List<Integer> temp, int start)
    {
        if (target < 0) return;
        if(target == 0)
        {
            res.add(new ArrayList<>(temp));
            return;
        }
        for(int i=start; i<nums.length; i++)
        {
             if (i > start && nums[i] == nums[i - 1])
                continue;
            temp.add(nums[i]);
            Func(nums, target-nums[i], res, temp, i+1);
            temp.remove(temp.size() - 1);
        }
    }
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(candidates);
        Func(candidates, target, res, new ArrayList<>(), 0);
        return res;
    }
}