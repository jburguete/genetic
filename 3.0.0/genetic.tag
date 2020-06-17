<?xml version='1.0' encoding='UTF-8' standalone='yes' ?>
<tagfile>
  <compound kind="file">
    <name>adaptation.h</name>
    <path>/home/burguete/programas/genetic/3.0.0/</path>
    <filename>adaptation_8h.html</filename>
  </compound>
  <compound kind="file">
    <name>bits.h</name>
    <path>/home/burguete/programas/genetic/3.0.0/</path>
    <filename>bits_8h.html</filename>
  </compound>
  <compound kind="file">
    <name>entity.c</name>
    <path>/home/burguete/programas/genetic/3.0.0/</path>
    <filename>entity_8c.html</filename>
    <includes id="entity_8h" name="entity.h" local="yes" imported="no">entity.h</includes>
    <member kind="function">
      <type>void</type>
      <name>entity_new</name>
      <anchorfile>entity_8c.html</anchorfile>
      <anchor>afa4d76e1dbc42672750a284b8c140e47</anchor>
      <arglist>(Entity *entity, unsigned int genome_nbytes, unsigned int id)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>entity_init</name>
      <anchorfile>entity_8c.html</anchorfile>
      <anchor>aeaf648622c48fd1a360b24360fbd120b</anchor>
      <arglist>(Entity *entity, gsl_rng *rng)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>entity_free</name>
      <anchorfile>entity_8c.html</anchorfile>
      <anchor>a8e2f8fb55fdc820540fd691748f7d0aa</anchor>
      <arglist>(Entity *entity)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>entity.h</name>
    <path>/home/burguete/programas/genetic/3.0.0/</path>
    <filename>entity_8h.html</filename>
    <class kind="struct">Entity</class>
    <member kind="function">
      <type>void</type>
      <name>entity_new</name>
      <anchorfile>entity_8h.html</anchorfile>
      <anchor>afa4d76e1dbc42672750a284b8c140e47</anchor>
      <arglist>(Entity *entity, unsigned int genome_nbytes, unsigned int id)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>entity_init</name>
      <anchorfile>entity_8h.html</anchorfile>
      <anchor>aeaf648622c48fd1a360b24360fbd120b</anchor>
      <arglist>(Entity *entity, gsl_rng *rng)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>entity_free</name>
      <anchorfile>entity_8h.html</anchorfile>
      <anchor>a8e2f8fb55fdc820540fd691748f7d0aa</anchor>
      <arglist>(Entity *entity)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>evolution.c</name>
    <path>/home/burguete/programas/genetic/3.0.0/</path>
    <filename>evolution_8c.html</filename>
    <includes id="bits_8h" name="bits.h" local="yes" imported="no">bits.h</includes>
    <includes id="sort_8h" name="sort.h" local="yes" imported="no">sort.h</includes>
    <includes id="entity_8h" name="entity.h" local="yes" imported="no">entity.h</includes>
    <includes id="population_8h" name="population.h" local="yes" imported="no">population.h</includes>
    <includes id="mutation_8h" name="mutation.h" local="yes" imported="no">mutation.h</includes>
    <includes id="reproduction_8h" name="reproduction.h" local="yes" imported="no">reproduction.h</includes>
    <includes id="adaptation_8h" name="adaptation.h" local="yes" imported="no">adaptation.h</includes>
    <includes id="selection_8h" name="selection.h" local="yes" imported="no">selection.h</includes>
    <includes id="evolution_8h" name="evolution.h" local="yes" imported="no">evolution.h</includes>
    <member kind="define">
      <type>#define</type>
      <name>DEBUG_EVOLUTION</name>
      <anchorfile>evolution_8c.html</anchorfile>
      <anchor>aa28c7f4d5b4940dd40bac14eec4d97ef</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>evolution_sort</name>
      <anchorfile>evolution_8c.html</anchorfile>
      <anchor>ad409e3a3635c02f1ef5bb3a5389930e3</anchor>
      <arglist>(Population *population)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>evolution_mutation</name>
      <anchorfile>evolution_8c.html</anchorfile>
      <anchor>aaa0fb1dc5ce55a79379ea152565cd628</anchor>
      <arglist>(Population *population, gsl_rng *rng)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>evolution_reproduction</name>
      <anchorfile>evolution_8c.html</anchorfile>
      <anchor>a3d6dc3525785135efc9b91355440988c</anchor>
      <arglist>(Population *population, gsl_rng *rng)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>evolution_adaptation</name>
      <anchorfile>evolution_8c.html</anchorfile>
      <anchor>ab18d859530a07cd2a89a00fd0b3d9eb0</anchor>
      <arglist>(Population *population, gsl_rng *rng)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>evolution.h</name>
    <path>/home/burguete/programas/genetic/3.0.0/</path>
    <filename>evolution_8h.html</filename>
    <member kind="function">
      <type>void</type>
      <name>evolution_sort</name>
      <anchorfile>evolution_8h.html</anchorfile>
      <anchor>ad409e3a3635c02f1ef5bb3a5389930e3</anchor>
      <arglist>(Population *population)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>evolution_mutation</name>
      <anchorfile>evolution_8h.html</anchorfile>
      <anchor>aaa0fb1dc5ce55a79379ea152565cd628</anchor>
      <arglist>(Population *population, gsl_rng *rng)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>evolution_reproduction</name>
      <anchorfile>evolution_8h.html</anchorfile>
      <anchor>a3d6dc3525785135efc9b91355440988c</anchor>
      <arglist>(Population *population, gsl_rng *rng)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>evolution_adaptation</name>
      <anchorfile>evolution_8h.html</anchorfile>
      <anchor>ab18d859530a07cd2a89a00fd0b3d9eb0</anchor>
      <arglist>(Population *population, gsl_rng *rng)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>genetic.c</name>
    <path>/home/burguete/programas/genetic/3.0.0/</path>
    <filename>genetic_8c.html</filename>
    <includes id="bits_8h" name="bits.h" local="yes" imported="no">bits.h</includes>
    <includes id="entity_8h" name="entity.h" local="yes" imported="no">entity.h</includes>
    <includes id="population_8h" name="population.h" local="yes" imported="no">population.h</includes>
    <includes id="reproduction_8h" name="reproduction.h" local="yes" imported="no">reproduction.h</includes>
    <includes id="selection_8h" name="selection.h" local="yes" imported="no">selection.h</includes>
    <includes id="evolution_8h" name="evolution.h" local="yes" imported="no">evolution.h</includes>
    <includes id="genetic_8h" name="genetic.h" local="yes" imported="no">genetic.h</includes>
    <member kind="define">
      <type>#define</type>
      <name>DEBUG_GENETIC</name>
      <anchorfile>genetic_8c.html</anchorfile>
      <anchor>ab698c4413c063b0a33eebab9ce80b5b6</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>genetic_get_variable</name>
      <anchorfile>genetic_8c.html</anchorfile>
      <anchor>ab98de3c17b66d23d36f3713d41d3060d</anchor>
      <arglist>(Entity *entity, GeneticVariable *variable)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>genetic_new</name>
      <anchorfile>genetic_8c.html</anchorfile>
      <anchor>ab844dcb1c74432af7837b62f4b0d5fc6</anchor>
      <arglist>(unsigned int nvariables, GeneticVariable *variable, unsigned int nentities, double mutation_ratio, double reproduction_ratio, double adaptation_ratio, double threshold)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>genetic_algorithm</name>
      <anchorfile>genetic_8c.html</anchorfile>
      <anchor>ac623d963ede167f5204479c022f0633f</anchor>
      <arglist>(unsigned int nvariables, GeneticVariable *variable, unsigned int nentities, unsigned int ngenerations, double mutation_ratio, double reproduction_ratio, double adaptation_ratio, const gsl_rng_type *type_random, unsigned long random_seed, unsigned int type_reproduction, unsigned int type_selection_mutation, unsigned int type_selection_reproduction, unsigned int type_selection_adaptation, double threshold, double(*simulate_entity)(Entity *), char **best_genome, double **best_variables, double *best_objective)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>genetic_algorithm_default</name>
      <anchorfile>genetic_8c.html</anchorfile>
      <anchor>afcb09dcfc85c04f52bb2a851f3cd6625</anchor>
      <arglist>(unsigned int nvariables, GeneticVariable *variable, unsigned int nentities, unsigned int ngenerations, double mutation_ratio, double reproduction_ratio, double adaptation_ratio, unsigned long random_seed, double threshold, double(*simulate_entity)(Entity *), char **best_genome, double **best_variables, double *best_objective)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>genetic.h</name>
    <path>/home/burguete/programas/genetic/3.0.0/</path>
    <filename>genetic_8h.html</filename>
    <includes id="entity_8h" name="entity.h" local="yes" imported="no">entity.h</includes>
    <includes id="population_8h" name="population.h" local="yes" imported="no">population.h</includes>
    <class kind="struct">GeneticThreadData</class>
    <member kind="function">
      <type>double</type>
      <name>genetic_get_variable</name>
      <anchorfile>genetic_8h.html</anchorfile>
      <anchor>ab98de3c17b66d23d36f3713d41d3060d</anchor>
      <arglist>(Entity *entity, GeneticVariable *variable)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>genetic_new</name>
      <anchorfile>genetic_8h.html</anchorfile>
      <anchor>ab844dcb1c74432af7837b62f4b0d5fc6</anchor>
      <arglist>(unsigned int nvariables, GeneticVariable *variable, unsigned int nentities, double mutation_ratio, double reproduction_ratio, double adaptation_ratio, double threshold)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>genetic_algorithm</name>
      <anchorfile>genetic_8h.html</anchorfile>
      <anchor>ac623d963ede167f5204479c022f0633f</anchor>
      <arglist>(unsigned int nvariables, GeneticVariable *variable, unsigned int nentities, unsigned int ngenerations, double mutation_ratio, double reproduction_ratio, double adaptation_ratio, const gsl_rng_type *type_random, unsigned long random_seed, unsigned int type_reproduction, unsigned int type_selection_mutation, unsigned int type_selection_reproduction, unsigned int type_selection_adaptation, double threshold, double(*simulate_entity)(Entity *), char **best_genome, double **best_variables, double *best_objective)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>genetic_algorithm_default</name>
      <anchorfile>genetic_8h.html</anchorfile>
      <anchor>afcb09dcfc85c04f52bb2a851f3cd6625</anchor>
      <arglist>(unsigned int nvariables, GeneticVariable *variable, unsigned int nentities, unsigned int ngenerations, double mutation_ratio, double reproduction_ratio, double adaptation_ratio, unsigned long random_seed, double threshold, double(*simulate_entity)(Entity *), char **best_genome, double **best_variables, double *best_objective)</arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>ntasks</name>
      <anchorfile>genetic_8h.html</anchorfile>
      <anchor>ad8caa56c58b5da3d9c20c7213d146363</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>nthreads</name>
      <anchorfile>genetic_8h.html</anchorfile>
      <anchor>a47a6a7abf51f20275a0453efd67c8de0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>GMutex</type>
      <name>mutex</name>
      <anchorfile>genetic_8h.html</anchorfile>
      <anchor>ac1bbdd709ee463b4624a6e17f0c76148</anchor>
      <arglist>[1]</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>mutation.h</name>
    <path>/home/burguete/programas/genetic/3.0.0/</path>
    <filename>mutation_8h.html</filename>
  </compound>
  <compound kind="file">
    <name>population.c</name>
    <path>/home/burguete/programas/genetic/3.0.0/</path>
    <filename>population_8c.html</filename>
    <includes id="bits_8h" name="bits.h" local="yes" imported="no">bits.h</includes>
    <includes id="entity_8h" name="entity.h" local="yes" imported="no">entity.h</includes>
    <includes id="population_8h" name="population.h" local="yes" imported="no">population.h</includes>
    <member kind="function">
      <type>int</type>
      <name>population_new</name>
      <anchorfile>population_8c.html</anchorfile>
      <anchor>a4346c78e5772c03541929e08fc32022a</anchor>
      <arglist>(Population *population, GeneticVariable *variable, unsigned int nvariables, unsigned int genome_nbits, unsigned int nentities, double mutation_ratio, double reproduction_ratio, double adaptation_ratio, double threshold)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>population_init_genomes</name>
      <anchorfile>population_8c.html</anchorfile>
      <anchor>a568831c5f06d0d002671b1884cfccd1e</anchor>
      <arglist>(Population *population, gsl_rng *rng)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>population_free</name>
      <anchorfile>population_8c.html</anchorfile>
      <anchor>ab4ef8d8a4a1a5f2b44b8b4e56be10bbb</anchor>
      <arglist>(Population *population)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>population.h</name>
    <path>/home/burguete/programas/genetic/3.0.0/</path>
    <filename>population_8h.html</filename>
    <class kind="struct">GeneticVariable</class>
    <class kind="struct">Population</class>
    <member kind="function">
      <type>int</type>
      <name>population_new</name>
      <anchorfile>population_8h.html</anchorfile>
      <anchor>a4346c78e5772c03541929e08fc32022a</anchor>
      <arglist>(Population *population, GeneticVariable *variable, unsigned int nvariables, unsigned int genome_nbits, unsigned int nentities, double mutation_ratio, double reproduction_ratio, double adaptation_ratio, double threshold)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>population_free</name>
      <anchorfile>population_8h.html</anchorfile>
      <anchor>ab4ef8d8a4a1a5f2b44b8b4e56be10bbb</anchor>
      <arglist>(Population *population)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>population_init_genomes</name>
      <anchorfile>population_8h.html</anchorfile>
      <anchor>a568831c5f06d0d002671b1884cfccd1e</anchor>
      <arglist>(Population *population, gsl_rng *rng)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>reproduction.c</name>
    <path>/home/burguete/programas/genetic/3.0.0/</path>
    <filename>reproduction_8c.html</filename>
    <includes id="bits_8h" name="bits.h" local="yes" imported="no">bits.h</includes>
    <includes id="entity_8h" name="entity.h" local="yes" imported="no">entity.h</includes>
    <includes id="reproduction_8h" name="reproduction.h" local="yes" imported="no">reproduction.h</includes>
    <member kind="function">
      <type>void</type>
      <name>reproduction_init</name>
      <anchorfile>reproduction_8c.html</anchorfile>
      <anchor>a793a61036d3630a27744fae23bf37a5c</anchor>
      <arglist>(unsigned int type)</arglist>
    </member>
    <member kind="variable">
      <type>void(*</type>
      <name>reproduction</name>
      <anchorfile>reproduction_8c.html</anchorfile>
      <anchor>a559ce57446d05c09c0c14929eacff03f</anchor>
      <arglist>)(Entity *, Entity *, Entity *, unsigned int, gsl_rng *)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>reproduction.h</name>
    <path>/home/burguete/programas/genetic/3.0.0/</path>
    <filename>reproduction_8h.html</filename>
    <member kind="enumeration">
      <type></type>
      <name>ReproductionType</name>
      <anchorfile>reproduction_8h.html</anchorfile>
      <anchor>a62423339328c84b4cb7f7c95559b452a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>REPRODUCTION_TYPE_SINGLEPOINTS</name>
      <anchorfile>reproduction_8h.html</anchorfile>
      <anchor>a62423339328c84b4cb7f7c95559b452aa05eaa6294e00833a38ca0818c33c00b4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>REPRODUCTION_TYPE_DOUBLEPOINTS</name>
      <anchorfile>reproduction_8h.html</anchorfile>
      <anchor>a62423339328c84b4cb7f7c95559b452aabd99917371db044a4858cdc71cb71d56</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>REPRODUCTION_TYPE_MIXING</name>
      <anchorfile>reproduction_8h.html</anchorfile>
      <anchor>a62423339328c84b4cb7f7c95559b452aa77b82fb05e67c7c74ef15ba0508ecf83</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>reproduction_init</name>
      <anchorfile>reproduction_8h.html</anchorfile>
      <anchor>a793a61036d3630a27744fae23bf37a5c</anchor>
      <arglist>(unsigned int type)</arglist>
    </member>
    <member kind="variable">
      <type>void(*</type>
      <name>reproduction</name>
      <anchorfile>reproduction_8h.html</anchorfile>
      <anchor>a559ce57446d05c09c0c14929eacff03f</anchor>
      <arglist>)(Entity *, Entity *, Entity *, unsigned int, gsl_rng *)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>selection.c</name>
    <path>/home/burguete/programas/genetic/3.0.0/</path>
    <filename>selection_8c.html</filename>
    <includes id="entity_8h" name="entity.h" local="yes" imported="no">entity.h</includes>
    <includes id="population_8h" name="population.h" local="yes" imported="no">population.h</includes>
    <includes id="selection_8h" name="selection.h" local="yes" imported="no">selection.h</includes>
    <member kind="function">
      <type>void</type>
      <name>selection_init</name>
      <anchorfile>selection_8c.html</anchorfile>
      <anchor>acb595ca3818d9f7527f88855281d262c</anchor>
      <arglist>(unsigned int mutation_type, unsigned int reproduction_type, unsigned int adaptation_type)</arglist>
    </member>
    <member kind="variable">
      <type>void(*</type>
      <name>selection_mutation</name>
      <anchorfile>selection_8c.html</anchorfile>
      <anchor>aa359ba483cbea98c619b2b01cb38a771</anchor>
      <arglist>)(Population *, Entity **, gsl_rng *)</arglist>
    </member>
    <member kind="variable">
      <type>void(*</type>
      <name>selection_reproduction</name>
      <anchorfile>selection_8c.html</anchorfile>
      <anchor>ab134bc1689cf7ae39265b93568bdf527</anchor>
      <arglist>)(Population *, Entity **, Entity **, gsl_rng *)</arglist>
    </member>
    <member kind="variable">
      <type>void(*</type>
      <name>selection_adaptation</name>
      <anchorfile>selection_8c.html</anchorfile>
      <anchor>a3f330ab39eec3417c783ee30b21a0d7f</anchor>
      <arglist>)(Population *, Entity **, gsl_rng *)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>selection.h</name>
    <path>/home/burguete/programas/genetic/3.0.0/</path>
    <filename>selection_8h.html</filename>
    <member kind="enumeration">
      <type></type>
      <name>SelectionMutationType</name>
      <anchorfile>selection_8h.html</anchorfile>
      <anchor>a351211cc69812c47d848db915e4ffcaf</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>SELECTION_MUTATION_TYPE_RANDOM</name>
      <anchorfile>selection_8h.html</anchorfile>
      <anchor>a351211cc69812c47d848db915e4ffcafa98df5b485f286dde3b01dccc9d52d768</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>SELECTION_MUTATION_TYPE_BESTOF2</name>
      <anchorfile>selection_8h.html</anchorfile>
      <anchor>a351211cc69812c47d848db915e4ffcafacaeae011eaf4b2514d7560880f3a4d88</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>SELECTION_MUTATION_TYPE_BESTOF3</name>
      <anchorfile>selection_8h.html</anchorfile>
      <anchor>a351211cc69812c47d848db915e4ffcafa9f70aa02557f0fd042d9dc8962863de4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>SELECTION_MUTATION_TYPE_BEST</name>
      <anchorfile>selection_8h.html</anchorfile>
      <anchor>a351211cc69812c47d848db915e4ffcafa4f4125ccfa2467928cfe036e679019a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>SELECTION_MUTATION_TYPE_LINEARRANK</name>
      <anchorfile>selection_8h.html</anchorfile>
      <anchor>a351211cc69812c47d848db915e4ffcafaea90a8f1b23d4886deafabcd4c3a5158</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>SelectionReproductionType</name>
      <anchorfile>selection_8h.html</anchorfile>
      <anchor>a509c6a27c8fa76c68b17e7dc65a063b4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>SELECTION_REPRODUCTION_TYPE_RANDOM</name>
      <anchorfile>selection_8h.html</anchorfile>
      <anchor>a509c6a27c8fa76c68b17e7dc65a063b4a169195b32685d7bb661434ac8c9c37a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>SELECTION_REPRODUCTION_TYPE_BESTOF2</name>
      <anchorfile>selection_8h.html</anchorfile>
      <anchor>a509c6a27c8fa76c68b17e7dc65a063b4a2e31ce6342b8f6d7524da1bba4deb621</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>SELECTION_REPRODUCTION_TYPE_BESTOF3</name>
      <anchorfile>selection_8h.html</anchorfile>
      <anchor>a509c6a27c8fa76c68b17e7dc65a063b4a6017c8d2541d007d6b6c77b5ef0ebfa3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>SELECTION_REPRODUCTION_TYPE_BEST</name>
      <anchorfile>selection_8h.html</anchorfile>
      <anchor>a509c6a27c8fa76c68b17e7dc65a063b4a045b5a7eb2112295e69e27ff971422da</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>SELECTION_REPRODUCTION_TYPE_LINEARRANK</name>
      <anchorfile>selection_8h.html</anchorfile>
      <anchor>a509c6a27c8fa76c68b17e7dc65a063b4a40da66b5779af22cf199fa39257bc5ab</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>SelectionAdaptationType</name>
      <anchorfile>selection_8h.html</anchorfile>
      <anchor>a8e3818318a82b8e96a73d636fe25642c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>SELECTION_ADAPTATION_TYPE_RANDOM</name>
      <anchorfile>selection_8h.html</anchorfile>
      <anchor>a8e3818318a82b8e96a73d636fe25642ca1ad02c6b7cabefff481f7949db2d9f40</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>SELECTION_ADAPTATION_TYPE_BESTOF2</name>
      <anchorfile>selection_8h.html</anchorfile>
      <anchor>a8e3818318a82b8e96a73d636fe25642ca3ba570deee5e216d719ffd5851137c9f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>SELECTION_ADAPTATION_TYPE_BESTOF3</name>
      <anchorfile>selection_8h.html</anchorfile>
      <anchor>a8e3818318a82b8e96a73d636fe25642cada31a52b1f8a9b361f10e95a4104a4aa</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>SELECTION_ADAPTATION_TYPE_BEST</name>
      <anchorfile>selection_8h.html</anchorfile>
      <anchor>a8e3818318a82b8e96a73d636fe25642ca86fd21b67a9213f07e58f89e6ccca7e7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>SELECTION_ADAPTATION_TYPE_LINEARRANK</name>
      <anchorfile>selection_8h.html</anchorfile>
      <anchor>a8e3818318a82b8e96a73d636fe25642caabd41f426ca5fa5fc38fb26bd62d668a</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>selection_init</name>
      <anchorfile>selection_8h.html</anchorfile>
      <anchor>acb595ca3818d9f7527f88855281d262c</anchor>
      <arglist>(unsigned int mutation_type, unsigned int reproduction_type, unsigned int adaptation_type)</arglist>
    </member>
    <member kind="variable">
      <type>void(*</type>
      <name>selection_mutation</name>
      <anchorfile>selection_8h.html</anchorfile>
      <anchor>aa359ba483cbea98c619b2b01cb38a771</anchor>
      <arglist>)(Population *, Entity **, gsl_rng *)</arglist>
    </member>
    <member kind="variable">
      <type>void(*</type>
      <name>selection_reproduction</name>
      <anchorfile>selection_8h.html</anchorfile>
      <anchor>ab134bc1689cf7ae39265b93568bdf527</anchor>
      <arglist>)(Population *, Entity **, Entity **, gsl_rng *)</arglist>
    </member>
    <member kind="variable">
      <type>void(*</type>
      <name>selection_adaptation</name>
      <anchorfile>selection_8h.html</anchorfile>
      <anchor>a3f330ab39eec3417c783ee30b21a0d7f</anchor>
      <arglist>)(Population *, Entity **, gsl_rng *)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>sort.h</name>
    <path>/home/burguete/programas/genetic/3.0.0/</path>
    <filename>sort_8h.html</filename>
    <member kind="define">
      <type>#define</type>
      <name>INDEX_SORT_MERGE_MIN</name>
      <anchorfile>sort_8h.html</anchorfile>
      <anchor>ab6c9439ae5189f60bee252863c3ab4a8</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>test_genetic.c</name>
    <path>/home/burguete/programas/genetic/3.0.0/</path>
    <filename>test__genetic_8c.html</filename>
    <includes id="entity_8h" name="entity.h" local="yes" imported="no">entity.h</includes>
    <includes id="population_8h" name="population.h" local="yes" imported="no">population.h</includes>
    <includes id="reproduction_8h" name="reproduction.h" local="yes" imported="no">reproduction.h</includes>
    <includes id="selection_8h" name="selection.h" local="yes" imported="no">selection.h</includes>
    <includes id="evolution_8h" name="evolution.h" local="yes" imported="no">evolution.h</includes>
    <includes id="genetic_8h" name="genetic.h" local="yes" imported="no">genetic.h</includes>
    <member kind="function">
      <type>double</type>
      <name>evaluate</name>
      <anchorfile>test__genetic_8c.html</anchorfile>
      <anchor>a900ca87b4ab990ed2793f8235c15a447</anchor>
      <arglist>(Entity *entity)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>main</name>
      <anchorfile>test__genetic_8c.html</anchorfile>
      <anchor>a6d6b841d00afea11d5056811a58699a1</anchor>
      <arglist>(int argn, char **argc)</arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>ntasks</name>
      <anchorfile>test__genetic_8c.html</anchorfile>
      <anchor>ad8caa56c58b5da3d9c20c7213d146363</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>nthreads</name>
      <anchorfile>test__genetic_8c.html</anchorfile>
      <anchor>a47a6a7abf51f20275a0453efd67c8de0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>GMutex</type>
      <name>mutex</name>
      <anchorfile>test__genetic_8c.html</anchorfile>
      <anchor>ac1bbdd709ee463b4624a6e17f0c76148</anchor>
      <arglist>[1]</arglist>
    </member>
    <member kind="variable">
      <type>GeneticVariable</type>
      <name>v</name>
      <anchorfile>test__genetic_8c.html</anchorfile>
      <anchor>a7d5f293af1de7953467b391df902e6e5</anchor>
      <arglist>[2]</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Entity</name>
    <filename>structEntity.html</filename>
    <member kind="variable">
      <type>char *</type>
      <name>genome</name>
      <anchorfile>structEntity.html</anchorfile>
      <anchor>aab16824c3d1bace90f37359aae25b51a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>id</name>
      <anchorfile>structEntity.html</anchorfile>
      <anchor>a995f9a7bb4efb0257defcd05be2622e4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>nbytes</name>
      <anchorfile>structEntity.html</anchorfile>
      <anchor>a11b6441d680bcbbcc4f634222ad83a0c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>GeneticThreadData</name>
    <filename>structGeneticThreadData.html</filename>
    <member kind="variable">
      <type>unsigned int</type>
      <name>nmin</name>
      <anchorfile>structGeneticThreadData.html</anchorfile>
      <anchor>afd09757c4a3cf58d8e2b6bd1c0cab5fc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>nmax</name>
      <anchorfile>structGeneticThreadData.html</anchorfile>
      <anchor>aa6245baf80d5983744cdaa0785e2082b</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>GeneticVariable</name>
    <filename>structGeneticVariable.html</filename>
    <member kind="variable">
      <type>double</type>
      <name>maximum</name>
      <anchorfile>structGeneticVariable.html</anchorfile>
      <anchor>adab5a33cdd10c97cbc9312ecf6040a4e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>minimum</name>
      <anchorfile>structGeneticVariable.html</anchorfile>
      <anchor>a075f377c04738932bd9ac4156b10a892</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>nbits</name>
      <anchorfile>structGeneticVariable.html</anchorfile>
      <anchor>a2de21a88d998944f5028a8577c4fa0ce</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>location</name>
      <anchorfile>structGeneticVariable.html</anchorfile>
      <anchor>a8389ae3177d12998d5222e45947c4ee9</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Population</name>
    <filename>structPopulation.html</filename>
    <member kind="variable">
      <type>Entity *</type>
      <name>entity</name>
      <anchorfile>structPopulation.html</anchorfile>
      <anchor>ad0397ac92b3dcae0dc75a81e26d3b3e9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>GeneticVariable *</type>
      <name>variable</name>
      <anchorfile>structPopulation.html</anchorfile>
      <anchor>a5cab7bf4f7f2e5805d5581035ee955d4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double *</type>
      <name>objective</name>
      <anchorfile>structPopulation.html</anchorfile>
      <anchor>a94fca140194e57eae873d093fa5c74b5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>threshold</name>
      <anchorfile>structPopulation.html</anchorfile>
      <anchor>a55bee9467fb517c2df5a1e9416e670cc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>nvariables</name>
      <anchorfile>structPopulation.html</anchorfile>
      <anchor>a4efb8d55d8c8bfa32b4f3d3dd826584f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>genome_nbits</name>
      <anchorfile>structPopulation.html</anchorfile>
      <anchor>a30ee9b46b6c7c053c107187b7985e78d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>genome_nbytes</name>
      <anchorfile>structPopulation.html</anchorfile>
      <anchor>a74dc78c12c2530b00cedac50f8e60463</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>nentities</name>
      <anchorfile>structPopulation.html</anchorfile>
      <anchor>a2cc0c29de56bffb26ef0be2ae45f4d81</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>nsurvival</name>
      <anchorfile>structPopulation.html</anchorfile>
      <anchor>aab0f42c7cb46b713758fa3fd5bbae024</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>mutation_min</name>
      <anchorfile>structPopulation.html</anchorfile>
      <anchor>ab232f67ed3945da000eb53a1bb69587e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>mutation_max</name>
      <anchorfile>structPopulation.html</anchorfile>
      <anchor>a5f395adf46c487fd945934c346bdb43a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>reproduction_min</name>
      <anchorfile>structPopulation.html</anchorfile>
      <anchor>a8d2be216faa1cef9b605ce707014ce2a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>reproduction_max</name>
      <anchorfile>structPopulation.html</anchorfile>
      <anchor>ab0ffe2c42fb8655a58ac19a79fc1d006</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>adaptation_min</name>
      <anchorfile>structPopulation.html</anchorfile>
      <anchor>a84c98833121ac1416b1f0f43c7dcfc9e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>adaptation_max</name>
      <anchorfile>structPopulation.html</anchorfile>
      <anchor>aca3a3291fa6a299a79beb5d65b31daa2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>stop</name>
      <anchorfile>structPopulation.html</anchorfile>
      <anchor>a8db27bbf09f3b60b70e7af8998f9e370</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="page">
    <name>md_README</name>
    <title>GENETIC (3.0.0 version)</title>
    <filename>md_README.html</filename>
  </compound>
</tagfile>
