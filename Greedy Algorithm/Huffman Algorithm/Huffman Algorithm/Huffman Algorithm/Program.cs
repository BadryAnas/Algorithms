using System.Collections;

namespace Huffman_Algorithm
{

    public class HeapNode
    {
        public char data;
        public int freq;
        public HeapNode left;
        public HeapNode right;
        public HeapNode(char data, int freq)
        {
            left = right = null;
            this.data = data;
            this.freq = freq;
        }
    }

    public class Huffman
    {
        private char internal_char = (char)0;
        public Hashtable codes = new Hashtable();
        private PriorityQueue<HeapNode, int> minHeap = new PriorityQueue<HeapNode, int>();

        public Huffman(string message)
        {
            // Get the chars frequences
            Hashtable freqHash = new Hashtable();
            int i;
            for (i = 0; i < message.Length; i++)
            {
                if (freqHash[message[i]] == null)
                {
                    freqHash[message[i]] = 1;
                }
                else
                {
                    freqHash[message[i]] = (int)freqHash[message[i]] + 1;
                }
            }

            // Convert Hashtable to Queue[minHeap]
            i = 0;
            foreach (char k in freqHash.Keys)
            {
                HeapNode newNode = new HeapNode(k, (int)freqHash[k]);
                minHeap.Enqueue(newNode, (int)freqHash[k]);
                i++;
            }

            // we will use the priority queue to build the huffman map .. because we can move nodes with it's child nodes as we did in the presentation .. this is the ultimate reson why we using Prioriy queue
            HeapNode top, left, right;
            int newFreq;
            while (minHeap.Count != 1)
            {
                left = minHeap.Dequeue();
                right = minHeap.Dequeue();
                newFreq = left.freq + right.freq;
                top = new HeapNode(internal_char, newFreq);
                top.right = right;
                top.left = left;
                minHeap.Enqueue(top, newFreq);

            }

            //Generate Codes
            this.generateCodes(minHeap.Peek(), "");

        }

        private void generateCodes(HeapNode node, string str)
        {
            if (node == null)
            {
                return;
            }
            if (node.data != internal_char)
            {
                codes[node.data] = str;
            }

            generateCodes(node.left, str + "0");
            generateCodes(node.right, str + "1");


        }
    }



    internal class Program
    {
        static void Main(string[] args)
        {
            string msg = "The output from Huffman's algorithm can be viewed as a variable length code table for encoding a source symbol. The algorithm derives this table from the estimated probability or frequency of occurrence for each possible value of the source symbol. as in other entropy encoding methods, more common symbols are generally represented using fewer bits than less common symbols. Huffman's method can be efficiently implemented, finding a code in time linear to the number of input weights if these weights are sorted. However, although optimal among methods encoding symbols separately, Huffman coding is not always optimal among all compression methods it is replaced with arithmetic coding or asymmetric numeral systems if better compression ratio is required.";

            //msg = "internet";
            Huffman huff = new Huffman(msg);

            foreach (char k in huff.codes.Keys)
            {
                Console.Write(k + " ");
                Console.WriteLine(huff.codes[k]);
            }

        }
    }
}
