#ifndef TRIANGULATION_H
#define TRIANGULATION_H

#include "allTypes.h"
#include "commonUtils.h"

class Triangulation
{
public:
	Triangulation() {}
	~Triangulation() {}

	/// Triangulate a face (with steiner vts on its edges) using chord-based method.
	/// INPUT: 
	/// - a list of vert indices sorted around the face
	/// - the order according to which the vts are connected
	/// OUPUT:
	/// - a list of new triangles
	void triangulateChordBased(
		const vector<unsigned>& _v_sorted_indices, 
		 // connect seq storing pairs: <vi, and relative pos in _v_indices
		const vector< std::pair<unsigned,unsigned> >& _conn_seq,
		vector<TriFace>& _tri_faces
		);
};

#endif