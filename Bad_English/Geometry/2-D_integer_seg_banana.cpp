typedef long long ll;

struct pos{ // 2-D Geometry (integer)
	ll X, Y;
};

bool operator == (const pos &a, const pos &b){
	return a.X == b.X && a.Y == b.Y;
}

pos operator - (const pos &a, const pos &b){
	return pos{a.X - b.X, a.Y - b.Y};
}

pos operator + (const pos &a, const pos &b){
	return pos{a.X + b.X, a.Y + b.Y};
}

ll dot(pos a, pos b){ // a dot b
	return a.X * b.X + a.Y * b.Y;
}

ll cross(pos a, pos b){ // a cross b
	return a.X * b.Y - a.Y * b.X;
}

int ori(pos a, pos b){ // 1: CCW(L), -1: CW(R), 0: parallel
	ll re = cross(a, b);
	return re > 0 ? 1 : re < 0 ? -1 : 0;
}

bool btw(pos a, pos b, pos c){ // is b between a and c ?
	if(ori(b - a, c - a)) return 0;
	return dot(a - b, c - b) < 0;
}

bool banana(pos p1, pos p2, pos q1, pos q2){ // segments intersect ?
	if(p1 == q1 || p1 == q2 || p2 == q1 || p2 == q2) return 1;
	if(
		(ori(p2 - p1, q1 - p1) * ori(p2 - p1, q2 - p1) < 0) &&
		(ori(q2 - q1, p1 - q1) * ori(q2 - q1, p2 - q1) < 0)
	)return 1;
	if(
		btw(p1, q1, p2) ||
		btw(p1, q2, p2) ||
		btw(q1, p1, q2) ||
		btw(q1, p2, q2)
	)return 1;
	return 0;
}