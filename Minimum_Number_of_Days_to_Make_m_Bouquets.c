#include <stdio.h>
int isPossibleSol(int *bloomDay, int bloomDaySize, int m, int k, int mid) {
    int count = 0;
    for (int i = 0; i < bloomDaySize; i++) {   
        if (bloomDay[i] <= mid) {
            count++;
            if(count == k) {
                count = 0;
                m--;
            }
        } else {
            count = 0;
        } if (m == 0) {
            return 1;
        }
    } return m == 0 ? 1 : 0;
}
int minDays(int *bloomDay, int bloomDaySize, int m, int k) {
    if (m * k > bloomDaySize) return -1;
    int s = 0;
    int e = bloomDay[0];
    for (int i = 0; i < bloomDaySize; i++) {
        if (bloomDay[i] > e) {
            e = bloomDay[i];
        }
    }
    int ans = -1;
    int mid = s + (e - s) / 2;
    while(s <= e) {
        if (isPossibleSol(bloomDay, bloomDaySize, m, k, mid)) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        } mid = s + (e - s) / 2;
    } return ans;
}
int main() {
    int bloomDay[] = {841105808, 720432705, 739696442, 467031911, 857812300, 80833799, 67036261, 963834068, 508579727, 10547445, 516472191, 449992770, 986593395, 571939554, 320253955, 293030387, 799189609, 48350930, 668202516, 76025123, 558251893, 108894691, 456096112, 159405573, 583984659, 996693439, 766024285, 544376329, 992291346, 367096416, 213738238, 28833488, 24382435, 220382669, 31490678, 433112229, 850027577, 467567527, 781139939, 975307758, 141087529, 33254883, 192167794, 764093446, 783684924, 396796027, 351285173, 55398839, 852098549, 290554030, 781638450, 142617264, 219611203, 898282274, 199283997, 907256237, 569468195, 262684630, 161924885, 97310050, 775095917, 58279757, 360618404, 736247458, 137705638, 495211969, 676288328, 736897318, 427509325, 114948947, 750135250, 521760509, 446218994, 686459783, 461404673, 3965477, 692967900, 966284293, 747722839, 918608474, 524423594, 109918216, 981797708, 999832460, 804013137, 446798895, 107656220, 16597342, 253738199, 426585312, 957739245, 282739320, 477309039, 565401518, 305624760, 61498611, 271149235, 900891656, 382111814, 93010516, 763290139, 504354644, 382177241, 914354531, 648603626, 359271752, 487021945, 873889472, 514264324, 55235816, 894535727, 681691041, 227326256, 10737685, 442367842, 170081331, 26781666, 40720063, 565555755, 107968481, 729897003, 115360673, 499388863, 816137330, 231823943, 175760190, 234071727, 107078832, 176991490, 27742673, 651705589, 82319372, 325721540, 528556234, 519544207, 336670383, 721791986, 35095903, 660801260, 820526509, 785426522, 505697538, 16891, 785767641, 582821598, 725962928, 791935374, 51946310, 500567660, 903959962, 743931875, 659672780, 532401110, 514001304, 811159008, 180826957, 273395119, 210943491, 855586082, 887970565, 679972703, 788727524, 141045661, 506829968, 506553717, 529427304, 613835524, 903156485, 32176860, 700304284, 19634709, 800515646, 317643165, 845763878, 234696296, 71344853, 928021350, 807275631, 373735079, 958032568, 377962420, 600946284, 42869806, 88258907, 533086691, 635652250, 54645010, 58711537, 287043002, 886373233, 491134229, 901606387, 114627656, 950870850, 363568836, 804087280, 691242946, 174902580, 595056341, 932227710, 822366528, 109400178, 521435566, 702259782, 887804583, 762401610, 8908170, 847255618, 42605211, 237950068, 28265088, 764576412, 544658020, 372723370, 660670629, 182130968, 157040422, 832053902, 600859278, 179807878, 164282837, 109713904, 549442318, 55859760, 909473773, 127071278, 314475656, 681940998, 383045534, 26423336, 845882411, 12748640, 260616204, 128541177, 329063405, 909712941, 405714341, 763362194, 543961650, 755753756, 182153552, 837220484, 230981152, 903793652, 956997764, 590892856, 239389883, 638369559, 359726742, 480699081, 44231297, 181999826, 736782189, 555693686, 472252984, 558519019, 704191884, 412462626, 597780718, 446522938, 680576901, 200589612, 693053570, 624232545, 158901841, 190852968, 175741056, 493462107, 120366847, 364117250, 175001006, 776184088, 139666036, 75474667, 314783385, 140700285, 185715443, 793913131, 287966787, 579060180, 113013454, 382575219, 467230763, 782527973, 622112035, 237829117, 476120128, 646180451, 438010888, 350191228, 932687420, 202060963, 40555365, 270266724, 998656871, 487292270, 343175672, 5974441, 171738411, 357846429, 46192549, 819151929, 238241929, 635518366, 114253968, 29355741, 684391712, 737984432, 191867317, 929468559, 252609586, 559620436, 114189504, 357836895, 424745294, 840682733, 449965017, 165265003, 290405866, 262842443, 792997955, 967445099, 17058563, 945913543, 500258583, 403313019, 522092612, 673038168, 729027602, 522851086, 614388068, 365980826, 594018763, 400581895, 418105764, 894879183, 402884536, 132870959, 686309700, 453790318, 267610218, 494715277, 666520656, 79094836, 677082475, 408729402, 823977899, 703885691, 655210105, 795567613, 342657947, 976644290, 989890204, 933691687, 620502990, 299119620, 936330847, 750667626, 337386557, 308321899, 830130868, 862036845, 866546702, 584271408, 405313159, 95322998, 627227252, 531359659, 962845833, 489314021, 289676495, 800180667, 351832979, 132351277, 348999694, 573921664, 736879122, 324544438, 279821781, 699460169, 692587226, 389784520, 777970059, 584902229, 746281977, 867869335, 552649947, 343053591, 922631130, 430849008, 28423384, 211430323, 91062445, 16504035, 918650442, 790026387, 114820698, 349364106, 430025653, 454158688, 864143927, 591548364, 129855148, 756902029, 270738920, 460590082, 779740841, 504745369, 52589167, 592732120, 520655474, 49415426, 310111956, 735719167, 339445951, 19979550, 950198912, 571062700, 775165518, 91307854, 519882327, 825332897, 686545584, 881064133, 686761176, 407327592, 631619165, 910038763, 187919661, 13606742, 682009640, 164554857, 802357807, 236646466, 177683270, 792666179, 630185252, 242754298, 159867650, 73194249, 300136694, 432573329, 483232948, 201624002, 255255880, 629186616, 626587711, 784912558, 813816829, 992246032, 9558596, 746347723, 335400290, 444403407, 480851506, 834569651, 545923181, 840235644, 123403770, 918033694, 230595993, 869510260, 764730846, 86249118, 906901460, 673101332, 325376688, 46866090, 393393432, 775853922, 80108781, 758281438, 860059698, 610027649, 56727547, 620678973, 454712136, 269971149, 921753954, 865240734, 601684058, 708260332, 688884539, 114245661, 272567998, 903580642, 715770749, 860722926, 590235184, 264520776, 61698581, 463712988, 140975898, 448998076, 586917404, 225077657, 991048102, 739500736, 745746734, 882368619, 282097639, 136208812, 694706241, 833692261, 905686017, 838485291, 930718883, 631610470, 750410847, 332662112, 715947398, 24834304, 736162016, 286594713, 228201892, 208294980, 245811526, 971353924, 992239704, 448780322, 562126027, 179693746, 887528689, 609468167, 87557820, 265874528, 836060769, 408596950, 898828933, 770601667, 587220568, 145441124, 204771245, 905944975, 810352280, 675151280, 680900718, 897219601, 117974258, 655632459, 376603203, 178049234, 60160315, 647298111, 978236578, 36711142, 353898421, 109469567, 704411126, 308621010, 866570403, 646752819, 947379820, 621308490, 851860418, 364167937, 314332161, 813154670, 467284971, 604726229, 968600397, 146117967, 476471544, 506319918, 918649994, 534262727, 657193759, 745460223, 556412476, 655414863, 765231419, 944409970, 938841073, 692147189, 200616327, 344321437, 128992273, 382678328, 387518359, 473635442, 810545773, 299387331, 566664939, 624397140, 517821950, 902489825, 701164096, 475497131, 30010298, 592126279, 578644634, 904029145, 936346298, 116800035, 628044925, 474142626, 544162048, 583575002, 894848424, 110861729, 959227702, 737153594, 547743550, 661593040, 542495411, 684346796, 975334853, 5119840, 884979863, 917806249, 817217361, 570007401, 730395450, 547525985, 986801308, 922694118, 361116562, 304044194, 911722025, 720472599, 307421577, 422117725, 283732069, 508658773, 527432314, 138607371, 955338558, 558954480, 64514574, 870779651, 909654837, 67271220, 979387988, 184547037, 956584207, 673937566, 434606264, 854185142, 471093442, 404226321, 62201, 70450630, 201789466, 813756588, 516460118, 33244762, 900614366, 574036333, 68016596, 131043829, 183699942, 511013308, 864624976, 914655518, 600127981, 791527025, 38362261, 761753901, 458197437, 324103690, 607971331, 378355348, 457831596, 754958633, 976242476, 759420927, 722454350, 126038799, 143791855, 832288155, 782824884, 696096733, 698953619, 218034689, 577941551, 149060708, 824829457, 826171227, 398961616, 542193235, 915472770, 95572784, 312511522, 799058026, 582327486, 809243361, 271577341, 184379824, 875459942, 566679478, 183236060, 697915267, 552578417, 656488495, 897016037, 992227045, 153973835, 936104342, 787164799, 965243103, 216346390, 534172899, 81035105, 546993845, 770233269, 703632773, 403265321, 347533766, 790998032, 210850406, 981697409, 208639731, 746229949, 115939147, 631104678, 861753729, 478119415, 48415022, 533981887, 549267637, 538988892, 786247560, 375335861, 173517736, 39843941, 936543663, 528677120, 556769506, 499054347, 789463944, 169876680, 874157664, 366387876, 99246225, 258180676, 977115073, 237979314, 762814275, 451077693, 382280585, 662925611, 494485179, 328237559, 58933896, 941387234, 866025853, 997881495, 982726316, 85169660, 116557563, 653822424, 289001299, 876758288, 330245106, 441923756, 294696626, 811873148, 340482440, 643617068, 946320523, 339588957, 917783112, 425905666, 353793834, 102435028, 921754059, 793411978, 676372434, 720409632, 386844024, 937984457, 367191574, 293926263, 439619156, 966181028, 12765407, 904944550, 184143235, 20077112, 441052480, 956912771, 199629560, 440107218, 567048344, 101013986, 236400410, 565901051, 234308643, 203799362, 17219297, 510241412, 413367834, 652181344, 931171519, 188460836, 462060679, 766957794, 365048523, 666940387, 339247966, 974118576, 541548048, 692816921, 626362721, 679479144, 688785556, 152047740, 751086824, 560703824, 617295909, 151879444, 112437170, 627860316, 379079679, 690423537, 794359790, 430496133, 251260446, 794434248, 607194357, 299760303, 666885556, 1016396, 758705746, 327823447, 439050478, 683752815, 100885914, 697346127, 311058392, 459794853, 635192351, 621089449, 807071892, 381622961, 244967139, 379112598, 133244536, 143669439, 406987047, 2357149, 658667071, 487276405, 529394009, 49607437, 426332356, 437315933, 902815353, 702842780, 911046925, 798728373, 125296923, 474462920, 381991039, 595370784, 137721583, 530172752, 932342271, 437756178, 476715116, 347842551, 856460344, 941318861, 960115713, 527263338, 639098899, 373953559, 333482648, 912335243, 304739960, 581056518, 286697645, 334073963, 575320738, 258624759, 598557746, 19926879, 505745732, 263379320, 405819276, 41605074, 898370653, 912524766, 933508395, 885527806, 952744847, 567117047, 403708115, 905785565, 938999338, 498308391, 498012261, 179123169, 591933028, 380892918, 999020106, 485297029, 353214686, 578684643, 810718371, 348692683, 195911937, 127392878, 485077676, 37991508, 110945819, 505758538, 198846314, 708488947, 627210118, 356080788, 529140691, 411979429, 526763395, 607757204, 528437979, 2889739, 305802293, 116891749, 956265488, 970642397, 469127673, 639097323, 243677233, 438617790, 42336533, 258793490, 971167772, 19822880, 747555344, 623282207, 33131808, 207319038, 672784389, 804905386, 319150240, 275317019, 941012947, 964510983, 785133579, 252921921, 146671766, 648237521, 510977755, 883476042, 977167259, 783943504, 83819710, 892445271, 885727129, 967648311, 408628617, 91702711, 88166323, 67307114, 248784974, 147297332, 177196519, 72781931, 779547378, 741412985, 40276573, 342493337, 396275879, 182369388, 756468764, 808378344, 433999933, 873998886, 40779165, 458616392, 716685076, 581366043, 14426179, 887151004, 858645158, 51425259, 990530896, 444373523, 154519427, 466654311, 999496512, 449682436, 781008639, 609754837, 180558201, 90478727, 396123799, 731319008, 274221234, 659928716, 599618533, 272912172, 489746185, 274785614, 41362809, 468026406, 921003087, 47906280, 364276701, 212695478, 271334143, 896224048, 812210175, 765198954, 16751701, 522034305, 507561981, 240366632, 241564965, 599788107, 182462794, 427953222, 938821343, 269596316, 292484225, 827641093, 946248877, 184340318, 898783773, 657971300, 96686677, 906655782, 563065088, 401277931, 963051328, 684021397, 116589184, 956710355, 37189608, 61800353, 134686242, 334511326, 101744638, 306098839, 815823248, 840024278, 789757526, 9506475, 870913738, 371631823, 509068968, 681953088, 80255806, 334635197, 890373506, 685577066, 96183071, 591751213, 576180282, 519903655, 831632610, 833199950, 2853055, 328706493, 697311081, 898167468, 429655515, 580062656, 44175989, 517974070, 351661960, 979337221, 657586952, 566314853, 919846603, 178534188, 50162245, 203149182, 40020514, 741511272, 819439782, 221965221, 14825820, 344456235, 917955471, 147431764, 345335805, 962025368, 566546815, 395838428, 287315645, 255383295, 963842089, 119416075, 594712567, 836148744, 68522304, 574529439, 923236268, 837889564, 76367846, 515873276, 199280316, 175103250, 696539049, 333872301, 769535868, 241960821, 67090043, 63818842, 339964160, 25963451, 683547577, 969038781, 853071837, 838528809, 906617857, 650022881, 519647933, 289440368, 150037315, 924039247, 418338071, 114616043, 626779415, 397373615, 751337355, 247118360, 130009436, 299563098, 511505118, 484166234, 414927625, 698001571, 225815950, 822711455, 633591896, 887624734, 121428928, 732017938, 744354564, 863890912, 310566742, 251877345, 8618778, 803593749, 383883191, 114018742, 275557594, 289891542, 423953847, 639862554, 129296349, 450595401, 119999281, 512330824, 977745206, 849767313, 166340768, 777025559, 690449972, 186812476, 551935586, 403714497, 457017, 668760266, 148872483, 470089644, 370426516, 9467117, 391448870, 620778397, 58789078, 659995991, 739998811, 929713616, 554189901, 572987193, 303147545, 28214838, 992787845, 418768495, 68171809, 966970669, 652998230, 795717677, 299272641, 330911806, 944344927, 543079516, 902429200, 844456524, 394394521, 364133581, 444649001, 121167901, 681855167, 341061781, 268514166, 564700654, 831210658, 607841590, 76367527, 26359859, 911644618, 739714427, 185845744, 872017898, 913775784, 352115279, 245331000, 666121459, 182236641, 41096479, 556358069, 460706935, 655831608, 629624563, 911183986, 412949735, 343426264, 329265604, 434477034, 512919873, 258384343, 330705633, 839977781, 453049397, 929427848, 382278020, 900741879, 569434602, 613277401, 911679689, 486539866, 82693187, 183413481, 739959278, 688747628, 892621734, 675872127, 458546637, 564658481, 933466430, 474593009, 21358198, 766887916, 153207744, 345664793, 124837743, 555675792, 923386486, 556681748, 400202207, 939219251, 570125806, 163623161, 746539284, 170421680, 52228399};
    int bloomDaySize = sizeof(bloomDay) / sizeof(int);
    int m = 23;
    int k = 34;
    int MinDays = minDays(bloomDay, bloomDaySize, m, k);
    printf("%d", MinDays);
    return 0;
}