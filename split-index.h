#ifndef SPLIT_INDEX_H
#define SPLIT_INDEX_H

struct index_state;
struct strbuf;

struct split_index {
	unsigned char base_sha1[20];
	struct index_state *base;
	unsigned int saved_cache_nr;
	int refcount;
};

struct split_index *init_split_index(struct index_state *istate);
int read_link_extension(struct index_state *istate,
			const void *data, unsigned long sz);
int write_link_extension(struct strbuf *sb,
			 struct index_state *istate);
void move_cache_to_base_index(struct index_state *istate);
void merge_base_index(struct index_state *istate);
void prepare_to_write_split_index(struct index_state *istate);
void finish_writing_split_index(struct index_state *istate);
void discard_split_index(struct index_state *istate);

#endif
