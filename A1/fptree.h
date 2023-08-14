#ifndef FPTREE_HPP
#define FPTREE_HPP

#include<vector>
#include<map>
#include<memory>
#include<set>

using Item = int;
using Transaction = std::vector<Item>;
using TransformedPrefixPath = std::pair<std::vector<Item>, uint64_t>;
using Pattern = std::pair<std::set<Item>, uint64_t>;


class FpNode
{
    public:
        const Item item;
        uint64_t frequency;
        std::shared_ptr<FpNode> next_node_in_ht;
        std::weak_ptr<FpNode> parent;
        std::vector<std::shared_ptr<FpNode>> children;
        
        FpNode(const Item&, const std::shared_ptr<FpNode>&);
};


class FpTree
{
    public:
        std::shared_ptr<FpNode> root;
        std::map<Item, std::shared_ptr<FpNode>> header_table;
        uint64_t minimum_support_threshold;

        FpTree(const std::string&, uint64_t);
        FpTree(const std::vector<Transaction>& transactions, uint64_t);

        bool empty() const;
};

std::set<Pattern> mine_fptree(const FpTree&);


#endif  // FPTREE_HPP