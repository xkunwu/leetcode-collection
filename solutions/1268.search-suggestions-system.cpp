class Solution {
    /** 1268. Search Suggestions System
     * https://leetcode.com/problems/search-suggestions-system/
     */
    typedef vector<array<size_t, 26>> Trie;
    Trie nodes;
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        auto insert = [](const char& c, Trie& nodes) {
            nodes.back()[c - 'a'] = nodes.size();
            nodes.emplace_back();
        };
        auto match = [](const string& word, Trie& nodes) -> bool {
            for (size_t ii = 0; ii < nodes.size() - 1; ++ii){
                if (ii == word.size()) return false;
                if (0 == nodes[ii][word[ii] - 'a']) return false;
            }
            return true;
        };
        sort(products.begin(), products.end());
        nodes.reserve(1000);
        nodes.emplace_back();
        vector<vector<string>> res;
        for (const auto& c: searchWord) {
            insert(c, nodes);
            vector<string> l;
            for (const auto& w: products) {
                if (match(w, nodes)) {
                    l.push_back(w);
                    if (3 == l.size()) break;
                }
            }
            res.push_back(move(l));
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> res;
        auto it = products.begin();
        string prefix;
        for (char c: searchWord) {
            prefix += c;
            auto lb = lower_bound(it, products.end(), prefix);
            vector<string> selects;
            for (int i = 0; i < 3; ++i) {
                if (lb + i < products.end() && (*(lb + i)).contains(prefix)) {
                    selects.push_back(*(lb + i));
                }
            }
            res.push_back(move(selects));
            it = lb;
        }
        return res;
    }
};

// ["tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzdqqgaqejetbnunqerptgas","zmmirsxdhyxvmdybjzondyvrkzeafhvualsivfueweuusmsxbttdeofzeripaqv","tyqcpfvorznmxxdzepfxabibcagilwjsqncxnpjqsxjzqqqbae","tyqcpfvacyrjvmadrmntxotgvgivdvcuwygpjfwcuppunolukrum","tyqcpfvrqwrcpusmfyhxaiasfbb","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzdqqgaqyalwiaj","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzdqqgaqejetbnuniwwjbdchidnpt","lfjkcljnd","zibrwfpwecubjlsjbkrhnvolnnzrqhdynloplzagwnuhpxhbvpxnqaifnln","ybswoottdgryxtupichpvqjmcoytrwnfgzrrnaejojvpzmttlzw","tyqcplghosxjviooiyddhvzzrhuuwkiosmgafxyajcdyqlmthqkoylxhtxdruw","okoscfpxcndzgbtsozdofgnomtglmoaewgzzjvrxezoq","cxkwvaytkxgafeltbanhsvxlorigkuxnsxlmhvwqm","iamtabcpdagicnvdvqcfykonsazrbdivxtczpgqgxjrifukmqjw","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzdqqgaqejetbneryahanhrhkal","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzdqqgaqejetbnunl","tyqcpfvorznmxxdzsuyushueegfrnlzbydnefcfagqnxglkulegntoml","zlovtmburfkd","vlzfaamutsfqefpafzffwhvpfw","bbufxzwpryyakbxuhwwplvdptgybbykqxirsrahsokviihxrawcbgwrktvgacmwtc","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzdqqgaqejetbnuniwwjbzw","kjundphljswl","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzdqqhlqnapfkcqpdb","stcphvgxvcaysehvrfdfllwvxf","epbtkgnnupbbdqgheyaks","gilhnlfkdz","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzdqqgaqejetbnuniwghy","yswdsvnzucvsdzrmeghevjrfuhoebfedvyvortaxppwqncmspctdcjlwdxfnc","baizdtmgozykukcrkapsnp","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzdqqgcsfjgtwqqubbhjkzmio","iblyydfzztmtyjmgrxvyjwcobfyxcgyrbtnfhhxswxahze","tyqcpfyggtmjahhpjzwhohvchyofsxwkehq","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzdqqgaqejetbnuniaymgkdduoabmp","gpsqlqorcbqffdxlnijgvzvxilnbkynwscuoymqyg","eidradnaqjwmucbrgtp","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzopnqxxcxshbhdmippldmcuxlvc","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzdqqgaqejetbfmryrbgicgzqecje","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuze","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzdqqgaqandxbuvshebs","tyqcqqxonxtwakxlrceyknbockvovdwumbjkfrgmudiafbqlflonfavpsrfq","tyqcpfvorznmxxdzsnkjnrrzpfourbghe","ziarqmfvzqpqhunfxwfwjtetotozkjaszznbtrvtxarysaxq","tyqcpfvorznmxfmlzlcuikpxvahtfbfipjcgmeusshufvnirwcopdnvnop","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvdertpdpdjsngezrnyjxotgonuigmqkgipgb","tyqcpfvorznmxxdzsnkjnrrzpfvfcvufmzzuqrjubsfzp","tyqcpfvorznmxxdzsnkjnrrzpfgknvqorqffebhoyfvgkspenqpcmvoxpybkjg","oqojrvinnhlwuqllcsabkpfiusfucpjbsxzzhlgduawaqyp","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzdqqgaqejetbnuniwwjbdchviaxsw","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzdqqgaqnzudhzclswotlbgdffwiekw","csgadyglxddodloklsegvsbtgtkloklmxkbxxyorcqwybktuzpyeaqasn","tyqitegmijccjwxuwvchbvuvllmgsdugzxdkiqvnllhmsjyskxpzzds","tyqcpfvorznigwmavbguxwhunsshdybhzszxvlnpingqgaghkqzeynbbbhgcxeydir","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzdqqgaqejetbnunflh","tyqcpfvorznmbwmhfmudnurhismirfgvojpdmclw","tyqcpfvjijiwoup","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzdqqgaqejemb","tyqcpfvorznmxxdzsnkjhvabtzucyooctzzrgehlsuyinrrnzjilfpalvqgwoey","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzdqqgaqejetbnuniwwjbdchvie","tyqcpfvorznmxxxvjwfgcwegpibuifhfxyomnicutaegshpnschktxknqytritr","tyqcpfvorznetvhiaobezckojwjbeg","tyqcpfvorzmjabuccipqln","frutebajqddrtrsmabfmdcgipssymldwscxbbrbpb","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzdqqgaqejetbnuniwwjbdchviotvqi","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzdqqgaqejetbnuniwwjbdchxeyrnlh","yaxaddctugikoutgcwqsdekghoemtooljxvysnzqqvgpc","tyqcpfvorznmxxdzsnkjn","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzdqqggjwxdvqesbgrqei","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckoktdj","mzwjshgbgbdogqbrhfgbjkrqogyynbdwwkdclsbpynlrhxeucuuo","tyqcpfvorznmxxdzsnkjnrrztrqgpbvvxm","u","tyqcpfvorznmxjnsgyirdtzpwywpnrvgadkmdjghlmerbqysaebyge","tyqcpfvorznmxxdzsnkjnrkjelwoqorxsnyjqdnxfava","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzdqqgaqejetbnuniwwjbdchvqqy","hcav","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzdqqgaqejetbnuniwwjbdchviof","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzdqqgaqejetbnuniwreznx","yesupowwycvcdbknhrkfyvnpoqtdhcbhybqvhnvgukoohh","hcvlnbmcrepblcqrvwpfsyevlpyldptubnxkntqhpounxjcw","lwaxzivycjkanvikqpbrvdvjkaclyuyfitwfycsnfwjg","tkruiswrcbzsbkwbhhvjzzuuiayqzbxjosjssacislcvbtcojpmyatkfgyx","ftujoohzvjonlwxwskeydoxpfvbvrdndbhgpuvykif","tyqcpfvorznmxxdzsnkjnrrzpfgknvqqngbpbdtufkgunalbekxbkpajlgbjtqmswh","tyqcpfvorznmxxdzsnkjnrrzpewgvvnicz","tyqcpfvorznmxxdzsnkjnrrzpfgknjxnepksgdzwxsbziwdzsiiyarxhtpp","jumcvboxaxjfybdlezcjrarolxjtsuweaigkiudusinfmnczdualqzlpwkm","tyqcpfvoxegnpqesbaugr","bteznmwyh","rtbpifxevchngjnlumvtqtpebgtoznvvrzfxqzmcktoxydbstbvukrunnyeqwfd","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzdqqgaqejysfrlewzsgukyahggau","mvrrbfbfwyrxooopgcbwmtjfepejyfrqdkyaqencqqlagoilrtdndfyn","tyqcpfvorznmyrzwhjxvhooytltygrakvgkqumrimazzhzoueyqnjz","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzdqqgaqejetbnuniwwjbdchviob","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzdqqgaqejetbnuniwwoyvqczogovza","tyqcpfvorznmxxdzsnkjnrrzpfgknvfnzshqqfpr","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzdqqgaqejetbnuniwwjghvqg","zqrnaierpnsigujuxrftdiauazddadqmrwcimxyztwumwzyjcrqvuexnitdecfgo","xusxbbilivpovzsjvfsdnacipk","tyqcpfvorznmxxdzkbqgrgeolnwhtvlckmiattpmxwwtmlifnexxbgtpjslwhczrjlhr","eiuytvdzhcodcrdgthxynurtpsdyguupijjluucpfinrfnsjkdbbzexfmctejlgvd","tyqcpfudqjrabwwvdvwmsyscnazaxpsjjhetouegipqevvointclztzummwrrbntjlsj","tyqcpfvobzfvbiuoktjcqjfx","tyqcpfvorznmxxdzsnamc","ajqpomnpmsayhelmhfehjbvjaeszqigfqyuixbtyjy","jpfxangixfavlhcssecxljksydrjxmaldhwpftinywtbmffsmtslefcuddk","txryxhtutwdrqmpcapbcrlmhzsobueefwfekusmmylr","etzqiepphjcleaocnwljcdn","tyqcpfvokfxlbmbzmitacnromkoaoxl","iddmxxcmwecfutbrbqeihhlnypckofuhkbydmljfemzrvlxsuskxkbgviybzu","tyqcpfvorznmxxdzwilcfwrdlfqppdnuvgltuoooppwyomtvtggmsfxsxievdlsyame","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvzquhbkvburnhmerkuabrfcjwanzmfenz","tyqcpqgaus","zsbcqgctsjdjyfkdvcehawsqzacafwtjmhemfygdahkexvmkqkcehvek","tyqcpfvorznmxxdzsnkjfesxjshxtlinfjltdfl","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzdqqgaqejetbnubpoqoghhgbpew","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzdqqgaqejetbnuniwwjbdcuudsuqq","tyqcpgwivyfquxqhbkjbioekqbsd","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzdqqgaqejetbnudxocavmwpggka","tyqcpfvorznmxxdzsnkjnrrzpfgknvnlxdokehsjhiohwdeyikeajzipztzhwmxc","pmpoycdxttisazazsgiswnsnhdmejpjbygvtjhwqydeugbouekvornbeiwmpehikbz","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzdqqgaqejetbnuniwcpoxr","qmgnrjtavzsqtwareroiihendgcvbzbcolvfoanmixxrxdtnmtevvv","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzdqqgaqejetbnunix","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzdqqgaqejetxpdyhmk","tyqcpfvorznmxxdzsnkjnrfmy","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzdqqgaqejetaoqgbczdcemzlmqemy","tyqcpfzmlffhifutomuvfvwaqatopvur","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvdvagddprewvlgx","ozmyertmnlwybntwxmpynuynhqdbqhosvjwexzqgvdtnvxexxwwwwhqktmzbfkjfn","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckohyof","rniiqnzbctzeyeeyrxhfzqgbccplsncvtswcrqmevplfzadlulazmpmhdojwaokn","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzakckmtmjxx","tyqcpfvorznmxxdzsnkjnrrzpfgkhdwienfhpsqbyrvotbgchkkmvk","tyqcpfvorznmxxdzsnkjnrrumaqtylptffsjzygeumkahutdmalkqtrhtgrsrqcyyti","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzdqqgaqejetbnuniwwjbdchvioncnr","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzdqqgaqejetbnuniwwjbdchvigzpo","tyqcpfvorznmxxdzsnkjnrrzpfgkeduq","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzdqqgaqejetbnccdnakfkhtg","lhehmbyzcnlwvr","tyqcpfvojuuprlby","wds","tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzdqqvegfwmtdcrvdb","tyqcpfvorznpkeynkmbbyptclmhxxlyjzejqbcatgfrmkbbmxs","tyqcpfvorznmiqmfrhihxsagizcrwyaukrjwbbgrxdzknq","ghhlssixrouzbqcpmxzmsnybaygtb","jndewk","tyqcpfvorznmxxdzsnkjnrrzpdqanmxattjhgnflnoyynevsxvpbwfmfrnlc"]
// "tyqcpfvorznmxxdzsnkjnrrzpfgknvqvderckuzdqqgaqejetbnuniwwjbdchviotvdticwxwcliylrpvrokbcguhnfvpd"