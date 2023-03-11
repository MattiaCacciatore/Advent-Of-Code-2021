// Mattia Cacciatore - Computer Science student at the University of Genoa - Italy
#include<cstdlib>   // srand()
#include<ctime>     // time()
#include<algorithm> // sort
#include "AoC12_part1.h"
//---------------------------------ADVENT OF CODE 2021 - DAY 12 - PART I ----------------------------------
const std::string start = "start";
const std::string end = "end";
//---------------------------------------------HELPER FUNCTIONS--------------------------------------------
// It sets all caves unvisited except the first one (aka start).
void set_unvisited(std::vector<cave> &caves){
	for(size_t i = 0; i < caves.size(); ++i){ 
		if(caves[i].label != start)
			caves[i].visited = false;
	}
}
// It set the flag 'visited' to true for the 'c' cave.
void set_visited(const std::string &c, std::vector<cave> &caves){
	for(size_t i = 0; i < caves.size(); ++i){ 
		if(caves[i].label == c){
			caves[i].visited = true;
			break;
		}
	}
}
// It finds the 'c' cave in the sequence and return his index.
ssize_t find_cave(const std::string &c, std::vector<cave> &caves){
	for(size_t i = 0; i < caves.size(); ++i){ 
		if(caves[i].label == c) return i;
	}
	return -1;
}
// It counts the number of unvisited caves in the sequence that apper in 'adjacent_cave'.
size_t count_rest_adjacent(std::vector<std::string> &adjacent_caves, std::vector<cave> &caves){
	size_t count = 0;
	for(size_t i = 0; i < adjacent_caves.size(); ++i){
		for(size_t j = 0; j < caves.size(); ++j){
			if(adjacent_caves[i] == caves[j].label){
				// Implicit cast from bool to int, 1 if it's true, 0 otherwise.
				count += (caves[j].big_cave || !caves[j].visited);
				break;
			}
		}
	}
	return count;
}
// It returns the index of the unvisited cave.
ssize_t is_unvisited(const std::string &c, const std::vector<cave> &caves){
	for(size_t i = 0; i < caves.size(); ++i){
		// Short-circuit evaluation.
		if(caves[i].label == c && (!caves[i].visited || caves[i].big_cave)) return i;
	}
	return -1;
}

std::string find_path_random(std::vector<cave> &caves){
	size_t rac = 0; // Rest adjacent (unvisited) caves.
	std::string current_cave = "", path = "";
	for(size_t i = 0;;){
		// Get the current cave where the submarine is standing.
		if((current_cave = caves[i].label) == end){
			path += current_cave;
			return path;
		}
		path += current_cave + " ";
		// If the current cave isn't the end and there're no other
		// adjacent unvisited (or big) caves, it's over.
		if((rac = count_rest_adjacent(caves[i].adjacent_caves, caves)) == 0) return "";
		// Now it explores all adjacent unvisited caves.
		for(ssize_t j;;){
			// It chooses a random adjacent cave and checks if the current adjacent 
			// cave is unvisited or a big cave.
			j = rand() % caves[i].adjacent_caves.size();
			if(is_unvisited(caves[i].adjacent_caves[j], caves) != -1){
				set_visited(caves[i].adjacent_caves[j], caves);
				i = find_cave(caves[i].adjacent_caves[j], caves);
				break;
			}
		}
	}
	return "";
}
//------------------------------------------------FUNCTIONS------------------------------------------------
std::vector<cave> read_caves_from_file(const std::string &input){
	std::vector<cave> caves; // Caves sequence.
	std::ifstream ifs(input);
    if(ifs.good()){
    	std::vector<std::string> edges; // Edges, node pairs in position i and i+1.
    	const std::string delimiter = "-";
    	size_t pos;
        std::string line, node, node2;
        std::istringstream iss;
        for(;!ifs.eof();){
            getline(ifs, line);
			for(pos = 0;(pos = line.find(delimiter)) != std::string::npos;){
				// It gets the first node/cave, then it skips the "-" separator
				// and gets the second node/cave.
    			edges.push_back(line.substr(0, pos));
    			line.erase(0, pos + delimiter.length()); // "-"
    			edges.push_back(line);
			}
        }
        // Counting the number of nodes/caves (including start and end). 
		// tmp in order to keep the edges vector unmodified.
        std::vector<std::string> tmp(edges);
        std::sort(tmp.begin(), tmp.end());
		size_t no_nodes = std::unique(tmp.begin(), tmp.end()) - tmp.begin();
		// tmp now contains only the unique nodes. Removing start and end.
		tmp.assign(tmp.begin(), (tmp.begin() + no_nodes));
		tmp.erase(std::remove(tmp.begin(), tmp.end(), start), tmp.end());
		tmp.erase(std::remove(tmp.begin(), tmp.end(), end), tmp.end());
		// Making the sequence.
		cave s, e, c; // Start, end, cave.
		s.label = start;
		e.label = end;
		s.visited = true;
		s.big_cave = e.big_cave = e.visited = false;
		caves.push_back(s);
		for(size_t i = 0; i < tmp.size(); ++i){
			c.label = tmp[i];
			c.visited = false;
			c.big_cave = (tmp[i][0] >= 'A' && tmp[i][0] <= 'Z'); // Check if it's a big cave.
			caves.push_back(c);
		}
		caves.push_back(e);
		// + 2 because nodes/caves are in pair. edges[i] first node/cave, edges[i+1] second node/cave.
		for(size_t i = 0; i < (edges.size() - 1); i += 2){
			// It adds the second node in the sequence of the adjacent nodes of the
			// first one if it doesn't appear in the sequence.
			for(size_t j = 0; j < caves.size(); ++j){
				if(caves[j].label == edges[i]){
					if(std::find(caves[j].adjacent_caves.begin(), caves[j].adjacent_caves.end(), edges[i+1]) == caves[j].adjacent_caves.end())
						caves[j].adjacent_caves.push_back(edges[i+1]);
				}
				else if(caves[j].label == edges[i+1]){
					if(std::find(caves[j].adjacent_caves.begin(), caves[j].adjacent_caves.end(), edges[i]) == caves[j].adjacent_caves.end())
						caves[j].adjacent_caves.push_back(edges[i]);
				}
			}
		}
    }
    ifs.clear();
	return caves;
}

size_t all_paths(std::vector<cave> &caves, const uint64_t no_attempts){
	std::vector<std::string> paths;
	std::string candidate_path;
	srand(time(NULL)); // Setting the seed for random paths.
	
	for(uint64_t i = 0; i < no_attempts; ++i){
		set_unvisited(caves); // Reset.
		candidate_path = find_path_random(caves);
		if(candidate_path != "" && std::find(paths.begin(), paths.end(), candidate_path) == paths.end())
			paths.push_back(candidate_path);
	}
	return paths.size();
}