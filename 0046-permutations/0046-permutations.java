class Solution {
    void Func(int[] nums, List<Integer> temp, List<List<Integer>> res, int start)
    {
        if(temp.size() == nums.length)
        {
            res.add(new ArrayList<>(temp));
            return;
        }
        for(int i=0; i<nums.length; i++)
        {
            if(temp.contains(nums[i]))
                continue;
            temp.add(nums[i]);
            Func(nums, temp, res, i+1);
            temp.remove(temp.size() - 1);
        }
    }
    public List<List<Integer>> permute(int[] nums) {
        List<Integer> temp = new ArrayList<>();
        List<List<Integer>> res = new ArrayList<>();
        Func(nums, temp, res, 0);
        return res;
    }
}