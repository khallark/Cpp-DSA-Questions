#include <myList.h>
#include <unordered_map>
using namespace std;

List sliceTable(List sales, List attrs) {
    List output;
    
    // Add attribute names as the first row
    output.push_back(attrs);
    
    // Create a map for quick index lookups
    std::unordered_map<std::string, int> attrIndexMap;
    for (int i = 0; i < sales[0].size(); ++i) {
        attrIndexMap[sales[0][i]] = i; // Mapping attribute names to their indices
    }

    // Iterate over the sales data starting from the second row (first row is headers)
    for (int i = 1; i < sales.size(); ++i) {
        List currentRow;
        for (const auto& attr : attrs) {
            // Use the pre-computed index to get the value
            if (attrIndexMap.find(attr) != attrIndexMap.end()) {
                currentRow.push_back(sales[i][attrIndexMap[attr]]);
            }
        }
        output.push_back(currentRow);
    }

    return output;
}


int main() {

    // Sales Data Frame
    var sales = {
        {"region", "country", "item type", "sales channel", "order priority", "order date", "order id", "ship date", "units sold", "unit price", "unit cost", "total revenue", "total cost", "total profit"},
        {"Middle East and North Africa", "Libya", "Cosmetics", "offline", "M", "10/18/2014", "686800706", "10/31/2014", 8446, 437.20, 263.33, 3692591.20, 2224085.18, 1468506.02},
        {"North America", "Canada", "Vegetables", "online", "M", "11/7/2011", "185941302", "12/8/2011", 3018, 154.06, 90.93, 464953.08, 274426.74, 190526.34},
        {"Middle East and North Africa", "Libya", "Baby Food", "offline", "C", "10/31/2016", "246222341", "12/9/2016", 1517, 255.28, 159.42, 387259.76, 241840.14, 145419.62},
        {"Asia", "Japan", "Cereal", "offline", "C", "4/10/2010", "161442649", "5/12/2010", 3322, 205.70, 117.11, 683335.40, 389039.42, 294295.98},
        {"Sub-Saharan Africa", "Chad", "Fruits", "offline", "H", "8/16/2011", "645713555", "8/31/2011", 9845, 9.33, 6.92, 91853.85, 68127.40, 23726.45},
        {"Europe", "Armenia", "Cereal", "online", "H", "11/24/2014", "683458888", "12/28/2014", 9528, 205.70, 117.11, 1959909.60, 1115824.08, 844085.52},
        {"Sub-Saharan Africa", "Eritrea", "Cereal", "online", "H", "3/4/2015", "679414975", "4/17/2015", 2844, 205.70, 117.11, 585010.80, 333060.84, 251949.96},
        {"Europe", "Montenegro", "Clothes", "offline", "M", "5/17/2012", "208630645", "6/28/2012", 7299, 109.28, 35.84, 797634.72, 261596.16, 536038.56},
        {"Central America and the Caribbean", "Jamaica", "Vegetables", "online", "H", "1/29/2015", "266467225", "3/7/2015", 2428, 154.06, 90.93, 374057.68, 220778.04, 153279.64},
        {"Australia and Oceania", "Fiji", "Vegetables", "offline", "H", "12/24/2013", "118598544", "1/19/2014", 4800, 154.06, 90.93, 739488.00, 436464.00, 303024.00},
        {"Sub-Saharan Africa", "Togo", "Clothes", "online", "M", "12/29/2015", "451010930", "1/19/2016", 3012, 109.28, 35.84, 329151.36, 107950.08, 221201.28},
        {"Europe", "Montenegro", "Snacks", "offline", "M", "2/27/2010", "220003211", "3/18/2010", 2694, 152.58, 97.44, 411050.52, 262503.36, 148547.16},
        {"Europe", "Greece", "Household", "online", "C", "11/17/2016", "702186715", "12/22/2016", 1508, 668.27, 502.54, 1007751.16, 757830.32, 249920.84},
        {"Sub-Saharan Africa", "Sudan", "Cosmetics", "online", "C", "12/20/2015", "544485270", "1/5/2016", 4146, 437.20, 263.33, 1812631.20, 1091766.18, 720865.02},
        {"Asia", "Maldives", "Fruits", "offline", "L", "1/8/2011", "714135205", "2/6/2011", 7332, 9.33, 6.92, 68407.56, 50737.44, 17670.12},
        {"Europe", "Montenegro", "Clothes", "offline", "H", "6/28/2010", "448685348", "7/22/2010", 4820, 109.28, 35.84, 526729.60, 172748.80, 353980.80},
        {"Europe", "Estonia", "Office Supplies", "online", "H", "4/25/2016", "405997025", "5/12/2016", 2397, 651.21, 524.96, 1560950.37, 1258329.12, 302621.25},
        {"North America", "Greenland", "Beverages", "online", "M", "7/27/2012", "414244067", "8/7/2012", 2880, 47.45, 31.79, 136656.00, 91555.20, 45100.80},
        {"Sub-Saharan Africa", "Cape Verde", "Clothes", "online", "C", "9/8/2014", "821912801", "10/3/2014", 1117, 109.28, 35.84, 122065.76, 40033.28, 82032.48},
        {"Sub-Saharan Africa", "Senegal", "Household", "offline", "L", "8/27/2012", "247802054", "9/8/2012", 8989, 668.27, 502.54, 6007079.03, 4517332.06, 1489746.97},
        {"Australia and Oceania", "Federated States of Micronesia", "Snacks", "online", "C", "9/3/2012", "531023156", "10/15/2012", 407, 152.58, 97.44, 62100.06, 39658.08, 22441.98},
        {"Europe", "Bulgaria", "Clothes", "online", "L", "8/27/2010", "880999934", "9/16/2010", 6313, 109.28, 35.84, 689884.64, 226257.92, 463626.72},
        {"Middle East and North Africa", "Algeria", "Personal Care", "online", "H", "2/20/2011", "127468717", "3/9/2011", 9681, 81.73, 56.67, 791228.13, 548622.27, 242605.86},
        {"Asia", "Mongolia", "Clothes", "online", "L", "12/12/2015", "770478332", "1/24/2016", 515, 109.28, 35.84, 56279.20, 18457.60, 37821.60},
        {"Central America and the Caribbean", "Grenada", "Cereal", "online", "H", "10/28/2012", "430390107", "11/13/2012", 852, 205.70, 117.11, 175256.40, 99777.72, 75478.68},
        {"Central America and the Caribbean", "Grenada", "Beverages", "online", "M", "1/30/2017", "397877871", "3/20/2017", 9759, 47.45, 31.79, 463064.55, 310238.61, 152825.94},
        {"Sub-Saharan Africa", "Senegal", "Beverages", "offline", "M", "10/22/2014", "683927953", "11/4/2014", 8334, 47.45, 31.79, 395448.30, 264937.86, 130510.44},
        {"North America", "Greenland", "Fruits", "offline", "M", "1/31/2012", "469839179", "2/22/2012", 4709, 9.33, 6.92, 43934.97, 32586.28, 11348.69},
        {"Sub-Saharan Africa", "Chad", "Meat", "offline", "H", "1/20/2016", "357222878", "3/9/2016", 9043, 421.89, 364.69, 3815151.27, 3297891.67, 517259.60},
        {"Sub-Saharan Africa", "Mauritius" , "Personal Care", "online", "C", "1/1/2016", "118002879", "1/7/2016", 8529, 81.73, 56.67, 697075.17, 483338.43, 213736.74},
        {"Middle East and North Africa", "Morocco", "Beverages", "offline", "C", "6/1/2017", "944415509", "6/23/2017", 2391, 47.45, 31.79, 113452.95, 76009.89, 37443.06},
        {"Central America and the Caribbean", "Honduras", "Office Supplies", "online", "H", "6/30/2015", "499009597", "7/9/2015", 6884, 651.21, 524.96, 4482929.64, 3613824.64, 869105.00},
        {"Sub-Saharan Africa", "Benin", "Fruits", "online", "L", "1/28/2014", "564646470", "3/16/2014", 293, 9.33, 6.92, 2733.69, 2027.56, 706.13},
        {"Europe", "Greece", "Baby Food", "offline", "M", "4/8/2014", "294499957", "4/8/2014", 7937, 255.28, 159.42, 2026157.36, 1265316.54, 760840.82},
        {"Central America and the Caribbean", "Jamaica", "Beverages", "offline", "L", "9/4/2010", "262056386", "10/24/2010", 7163, 47.45, 31.79, 339884.35, 227711.77, 112172.58},
        {"Sub-Saharan Africa", "Equatorial Guinea", "Office Supplies", "online", "M", "5/2/2010", "211114585", "5/14/2010", 2352, 651.21, 524.96, 1531645.92, 1234705.92, 296940.00},
        {"Sub-Saharan Africa", "Swaziland", "Office Supplies", "offline", "H", "10/3/2013", "405785882", "10/22/2013", 9915, 651.21, 524.96, 6456747.15, 5204978.40, 1251768.75},
        {"Central America and the Caribbean", "Trinidad and Tobago", "Vegetables", "offline", "M", "3/6/2011", "280494105", "4/14/2011", 3294, 154.06, 90.93, 507473.64, 299523.42, 207950.22},
        {"Europe", "Sweden", "Baby Food", "online", "L", "8/7/2016", "689975583", "8/12/2016", 7963, 255.28, 159.42, 2032794.64, 1269461.46, 763333.18},
        {"Europe", "Belarus", "Office Supplies", "online", "L", "1/11/2011", "759279143", "2/18/2011", 6426, 651.21, 524.96, 4184675.46, 3373392.96, 811282.50},
        {"Sub-Saharan Africa", "Guinea-Bissau", "Office Supplies", "offline", "C", "5/21/2014", "133766114", "6/12/2014", 3221, 651.21, 524.96, 2097547.41, 1690896.16, 406651.25},
        {"Asia", "Mongolia", "Beverages", "online", "M", "8/3/2013", "329110324", "9/2/2013", 9913, 47.45, 31.79, 470371.85, 315134.27, 155237.58},
        {"Middle East and North Africa", "Turkey", "Meat", "online", "L", "10/5/2011", "681298100", "11/20/2011", 103, 421.89, 364.69, 43454.67, 37563.07, 5891.60},
        {"Sub-Saharan Africa", "Central African Republic", "Snacks", "offline", "L", "11/15/2016", "596628272", "12/30/2016", 4419, 152.58, 97.44, 674251.02, 430587.36, 243663.66},
        {"Sub-Saharan Africa", "Equatorial Guinea", "Office Supplies", "offline", "L", "4/3/2015", "901712167", "4/17/2015", 5523, 651.21, 524.96, 3596632.83, 2899354.08, 697278.75},
        {"Asia", "Laos", "Beverages", "online", "M", "3/22/2013", "693473613", "4/21/2013", 3107, 47.45, 31.79, 147427.15, 98771.53, 48655.62},
        {"Europe", "Armenia", "Meat", "online", "C", "8/2/2010", "489148938", "9/1/2010", 8896, 421.89, 364.69, 3753133.44, 3244282.24, 508851.20},
        {"Europe", "Greece", "Household", "online", "L", "1/5/2012", "876286971", "2/15/2012", 1643, 668.27, 502.54, 1097967.61, 825673.22, 272294.39},
        {"Middle East and North Africa", "Israel", "Personal Care", "offline", "H", "8/26/2015", "262749040", "8/30/2015", 2135, 81.73, 56.67, 174493.55, 120990.45, 53503.10},
        {"Asia", "Bhutan", "Meat", "online", "H", "12/9/2016", "726708972", "1/26/2017", 8189, 421.89, 364.69, 3454857.21, 2986446.41, 468410.80},
        {"Australia and Oceania", "Vanuatu", "Vegetables", "online", "L", "5/17/2012", "366653096", "5/31/2012", 9654, 154.06, 90.93, 1487295.24, 877838.22, 609457.02},
    };

    // cout << sliceTable(sales, {"order priority", "order date", "sales channel", "total profit"})[0].size();
    // cout << sales;

    return 0;
}