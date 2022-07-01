#include <bits/stdc++.h>
using namespace std;


vector<int> repeatedNumber(const vector<int>& A) {
    long long int n = A.size();
    long long int s, s1 = 0, p, p1 = 0, s2, p2;
    long long int x, y;
    s = (long long int)((double)(n + 1) * (double)(n / 2.0));
    p = (long long int)((double)(n + 1) * (double)(2 * n + 1) * double(n / 6.0));

    for (int i = 0; i < n; i++) {
        s1 += A[i];
        p1 += A[i] * A[i];
    }
    s2 = s - s1;
    p2 = p - p1;

    // cout << "\n\ns: " << s << " , s1: " << s1;
    // cout << "\n\np: " << p << " , p1: " << p1;
    // cout << "\n\ns2: " << s2 << " , p2: " << p2;

    x = (long long int)((double)s2 + (double)((double)p2 / (double)s2));
    x /= 2;
    y = x - s2;
    vector<int> ans;
    cout << "\n\nY: " << y << endl << endl;
    ans.push_back(y);
    ans.push_back(x);
    return ans;
}
int main()
{
    // vector<int> const arr = { 3, 1 ,2 ,5, 3 };
    // vector<int> arr = { 389, 299, 65, 518, 361, 103, 342, 406, 24, 79, 192, 181, 178, 205, 38, 298, 218, 143, 446, 324, 82, 41, 312, 166, 252, 59, 91, 6, 248, 395, 157, 332, 352, 57, 106, 246, 506, 261, 16, 470, 224, 228, 286, 121, 193, 241, 203, 36, 264, 234, 386, 471, 225, 466, 81, 58, 253, 468, 31, 197, 15, 282, 334, 171, 358, 209, 213, 158, 355, 243, 75, 411, 43, 485, 291, 270, 25, 100, 194, 476, 70, 402, 403, 109, 322, 421, 313, 239, 327, 238, 257, 433, 254, 328, 163, 436, 520, 437, 392, 199, 63, 482, 222, 500, 454, 84, 265, 508, 416, 141, 447, 258, 384, 138, 47, 156, 172, 319, 137, 62, 85, 154, 97, 18, 360, 244, 272, 93, 263, 262, 266, 290, 369, 357, 176, 317, 383, 333, 204, 56, 521, 502, 326, 353, 469, 455, 190, 393, 453, 314, 480, 189, 77, 129, 439, 139, 441, 443, 351, 528, 182, 101, 501, 425, 126, 231, 445, 155, 432, 418, 95, 375, 376, 60, 271, 74, 11, 419, 488, 486, 54, 460, 321, 341, 174, 408, 131, 115, 107, 134, 448, 532, 292, 289, 320, 14, 323, 61, 481, 371, 151, 385, 325, 472, 44, 335, 431, 187, 51, 88, 105, 145, 215, 122, 162, 458, 52, 496, 277, 362, 374, 26, 211, 452, 130, 346, 10, 315, 459, 92, 531, 467, 309, 34, 281, 478, 477, 136, 519, 196, 240, 12, 288, 302, 119, 356, 503, 527, 22, 27, 55, 343, 490, 127, 444, 308, 354, 278, 497, 191, 294, 117, 1, 396, 125, 148, 285, 509, 208, 382, 297, 405, 245, 5, 330, 311, 133, 274, 275, 118, 463, 504, 39, 99, 442, 337, 169, 140, 104, 373, 221, 499, 413, 124, 510, 159, 465, 80, 276, 83, 329, 524, 255, 387, 259, 397, 491, 517, 23, 4, 230, 48, 349, 412, 142, 114, 487, 381, 164, 35, 67, 498, 73, 440, 108, 226, 96, 132, 144, 207, 235, 33, 69, 128, 236, 364, 198, 475, 173, 493, 150, 90, 515, 111, 68, 232, 340, 112, 526, 492, 512, 495, 429, 146, 336, 17, 350, 251, 7, 184, 76, 380, 359, 293, 19, 49, 345, 227, 212, 430, 89, 474, 279, 201, 398, 347, 273, 37, 185, 177, 102, 304, 295, 422, 94, 426, 514, 116, 183, 180, 494, 42, 305, 152, 390, 30, 247, 451, 32, 388, 331, 78, 424, 368, 394, 188, 306, 449, 8, 214, 120, 179, 280, 511, 409, 338, 153, 507, 370, 461, 217, 161, 483, 147, 242, 86, 417, 268, 71, 462, 420, 167, 513, 379, 307, 522, 435, 113, 296, 457, 525, 45, 529, 423, 427, 2, 438, 64, 316, 46, 40, 13, 516, 367, 233, 110, 318, 250, 283, 216, 186, 310, 237, 377, 365, 175, 479, 378, 66, 414, 473, 165, 210, 50, 348, 372, 363, 339, 20, 168, 284, 415, 505, 206, 53, 223, 434, 202, 123, 399, 400, 135, 269, 428, 219, 456, 28, 464, 267, 489, 98, 391, 195, 366, 300, 484, 533, 229, 213, 149, 160, 256, 303, 530, 301, 29, 404, 344, 401, 220, 287, 9, 407, 170, 450, 523, 249, 72, 410, 3, 21, 200, 260 };
    vector<int> arr = { 898, 867, 718, 398, 385, 450, 397, 711, 36, 46, 84, 448, 402, 56, 801, 165, 623, 670, 459, 880, 654, 894, 804, 207, 736, 735, 596, 275, 246, 555, 173, 799, 597, 39, 202, 412, 642, 405, 27, 607, 191, 637, 566, 512, 478, 646, 356, 156, 225, 622, 699, 418, 625, 842, 37, 838, 537, 153, 227, 809, 256, 655, 539, 618, 662, 259, 720, 96, 863, 420, 739, 112, 477, 522, 364, 650, 656, 348, 717, 94, 827, 281, 466, 835, 557, 324, 544, 203, 803, 401, 702, 320, 417, 169, 876, 80, 490, 31, 878, 102, 508, 674, 341, 764, 162, 41, 21, 61, 444, 148, 550, 582, 424, 657, 463, 640, 115, 99, 409, 268, 233, 820, 608, 569, 291, 14, 381, 396, 265, 783, 451, 238, 870, 40, 287, 807, 713, 722, 72, 663, 882, 343, 790, 525, 146, 821, 372, 774, 822, 172, 363, 769, 600, 33, 185, 269, 23, 710, 748, 64, 357, 194, 7, 772, 267, 154, 584, 35, 370, 599, 406, 81, 567, 439, 323, 752, 49, 353, 257, 744, 28, 481, 709, 136, 171, 44, 760, 452, 123, 861, 147, 34, 684, 205, 696, 447, 143, 376, 794, 460, 15, 479, 134, 893, 593, 226, 800, 511, 475, 501, 392, 486, 170, 492, 211, 139, 457, 231, 379, 897, 742, 636, 304, 249, 190, 484, 866, 293, 282, 42, 427, 325, 507, 598, 524, 25, 91, 128, 639, 244, 726, 333, 892, 383, 676, 120, 845, 661, 697, 779, 581, 482, 440, 591, 700, 617, 13, 67, 59, 763, 686, 55, 133, 4, 765, 17, 404, 374, 87, 694, 887, 195, 271, 583, 561, 828, 258, 69, 411, 321, 721, 11, 648, 177, 780, 677, 183, 100, 30, 751, 784, 802, 592, 577, 336, 151, 318, 839, 125, 51, 380, 8, 317, 533, 747, 576, 415, 855, 761, 551, 113, 132, 167, 548, 88, 210, 130, 388, 122, 278, 161, 240, 860, 895, 200, 83, 531, 6, 212, 532, 884, 362, 446, 843, 305, 570, 19, 106, 602, 770, 500, 168, 580, 743, 594, 573, 806, 631, 295, 530, 888, 433, 758, 342, 825, 414, 368, 192, 725, 658, 487, 243, 564, 797, 872, 795, 833, 716, 108, 435, 898, 535, 745, 286, 58, 66, 138, 864, 502, 262, 78, 90, 426, 283, 808, 768, 496, 862, 245, 124, 673, 119, 436, 606, 52, 432, 824, 327, 869, 621, 706, 687, 358, 579, 740, 263, 241, 844, 756, 330, 707, 223, 796, 786, 701, 408, 438, 513, 554, 456, 160, 86, 127, 144, 247, 65, 377, 454, 729, 70, 563, 746, 150, 209, 57, 681, 261, 429, 775, 316, 50, 442, 877, 367, 48, 60, 235, 445, 131, 232, 879, 829, 164, 311, 319, 776, 834, 174, 434, 574, 889, 787, 53, 149, 630, 526, 468, 189, 79, 158, 817, 559, 868, 260, 347, 297, 230, 252, 410, 135, 105, 390, 695, 649, 54, 387, 300, 578, 187, 693, 301, 823, 394, 425, 422, 793, 109, 789, 724, 520, 635, 68, 9, 157, 181, 493, 754, 152, 874, 558, 273, 219, 814, 688, 560, 178, 359, 354, 727, 386, 47, 682, 875, 847, 886, 116, 441, 690, 504, 603, 782, 541, 816, 588, 309, 515, 103, 255, 375, 871, 759, 691, 495, 678, 811, 852, 815, 462, 773, 360, 104, 480, 217, 22, 443, 714, 361, 399, 675, 668, 184, 605, 216, 575, 288, 859, 294, 237, 335, 767, 851, 166, 214, 453, 213, 619, 708, 197, 497, 337, 595, 315, 458, 505, 611, 310, 873, 516, 638, 349, 351, 254, 145, 179, 236, 499, 12, 322, 461, 685, 274, 540, 307, 837, 126, 571, 704, 771, 329, 24, 785, 766, 633, 98, 373, 653, 624, 400, 193, 421, 298, 503, 75, 110, 626, 730, 350, 738, 885, 264, 196, 856, 629, 692, 665, 224, 523, 20, 248, 545, 137, 45, 391, 698, 93, 615, 549, 32, 218, 465, 689, 705, 781, 176, 819, 384, 26, 483, 491, 805, 467, 521, 117, 371, 198, 891, 1, 140, 366, 643, 382, 553, 590, 413, 723, 865, 679, 280, 627, 129, 29, 741, 10, 485, 813, 890, 737, 750, 632, 270, 734, 604, 416, 222, 518, 610, 18, 506, 338, 431, 514, 792, 651, 546, 175, 510, 572, 312, 95, 641, 529, 369, 519, 562, 242, 63, 292, 731, 92, 565, 89, 85, 777, 455, 118, 810, 666, 389, 613, 498, 542, 538, 470, 659, 289, 234, 798, 857, 313, 2, 279, 471, 715, 250, 660, 749, 220, 303, 585, 472, 517, 586, 299, 712, 494, 3, 228, 272, 644, 215, 334, 107, 812, 464, 253, 552, 332, 163, 180, 473, 719, 568, 680, 306, 849, 423, 266, 206, 469, 16, 159, 74, 476, 328, 609, 277, 82, 314, 628, 186, 77, 647, 755, 43, 428, 430, 703, 221, 652, 732, 634, 395, 831, 339, 407, 352, 182, 614, 547, 121, 667, 403, 836, 284, 840, 290, 788, 509, 308, 378, 841, 762, 620, 543, 97, 489, 850, 188, 437, 846, 449, 141, 204, 393, 728, 683, 664, 276, 589, 612, 5, 114, 239, 229, 896, 340, 345, 832, 757, 616, 556, 826, 296, 854, 753, 853, 285, 671, 73, 883, 536, 199, 419, 326, 528, 76, 365, 155, 142, 60, 302, 672, 38, 881, 474, 355, 791, 778, 101, 858, 587, 645, 331, 669, 251, 601, 62, 527, 208, 534, 848, 488, 818, 111, 201, 346, 830, 71, 344 };
    vector<int> ans;
    ans = repeatedNumber(arr);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}